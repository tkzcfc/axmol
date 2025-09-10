#pragma once

#define LIBYUV_API

#include "ebml_parser.h"

#define SVPNG_LINKAGE inline
#define SVPNG_OUTPUT std::vector<uint8_t>& d
#define SVPNG_PUT(u) d.push_back((uint8_t)(u));
#include "svpng.inc"

#include "libyuv.h"
#include "vpx_decoder.h"
#include "vp8dx.h"
#include <assert.h>
#include <chrono>
#include <functional>

extern void print_log(const std::string& log);


struct MyScopeGuard
{
    MyScopeGuard(std::function<void()> f)
    {
        func = f;
    }

    ~MyScopeGuard()
    {
        func();
    }

    std::function<void()> func;
};

namespace ax {
    // webm 解析后的容易使用的存储形态
    struct Webm {
        // 0: vp8;	1: vp9
        uint8_t codecId = 0;

        // 1: true
        uint8_t hasAlpha = 0;

        // 像素宽
        uint16_t width = 0;

        // 像素高
        uint16_t height = 0;

        // 总播放时长( 秒 )
        float duration = 0;

        // 所有帧数据长度集合( hasAlpha 则为 rgb / a 交替长度集合 )
        std::vector<uint32_t> lens;

        // 所有帧数据依次排列
        std::vector<uint8_t> data;

        // 所有帧 rgb / a 数据块指针( 后期填充 )
        std::vector<uint8_t*> bufs;

        // 总帧数( 后期填充 )
        uint32_t count = 0;

        // todo: 可能还有别的附加信息存储. 例如 中心点坐标, 显示缩放比
        // todo: 动画信息? 多少帧到多少帧 定义为一个动画? 每帧的显示延迟设定? 时间轴?

        Webm() = default;
        Webm(Webm const&) = delete;
        Webm(Webm&&) = default;
        Webm& operator=(Webm const&) = delete;
        Webm& operator=(Webm&&) = default;

        inline operator bool() {
            return count != 0;
        }

        // 填充基础数据或反序列化后继续 填充 bufs, count
        inline int Init() {
            count = (uint32_t)(hasAlpha ? lens.size() / 2 : lens.size());

            bufs.resize(lens.size());
            auto baseBuf = data.data();
            for (int i = 0; i < lens.size(); ++i) {
                bufs[i] = (uint8_t*)baseBuf;
                baseBuf += lens[i];
            }
            if (baseBuf != data.data() + data.size())
                return __LINE__;
            return 0;
        }

        inline void Clear() {
            codecId = 0;
            hasAlpha = 0;
            width = 0;
            height = 0;
            duration = 0;
            lens.clear();
            data.clear();
            bufs.clear();
            count = 0;
        }

        inline int GetFrameBuf(uint32_t const& idx, uint8_t const*& rgbBuf, uint32_t& rgbBufLen) {
            if (hasAlpha) return __LINE__;
            if (idx >= count) return __LINE__;
            rgbBuf = bufs[idx];
            rgbBufLen = lens[idx];
            return 0;
        }

        inline int GetFrameBuf(uint32_t idx, uint8_t const*& rgbBuf, uint32_t& rgbBufLen, uint8_t const*& aBuf, uint32_t& aBufLen) {
            if (!hasAlpha) return __LINE__;
            if (idx >= count) return __LINE__;
            idx *= 2;
            rgbBuf = bufs[idx];
            aBuf = bufs[idx + 1];
            rgbBufLen = lens[idx];
            aBufLen = lens[idx + 1];
            return 0;
        }

        // 从 .webm 读出数据并填充到 wm. 成功返回 0
        inline int LoadFromWebm(uint8_t* data, size_t dataLen) {
            this->Clear();
            // 开始解析 ebml 头
            auto&& ebml = parse_ebml_file(data, dataLen/*, 1*/);
            auto&& segment = ebml.FindChildById(EbmlElementId::Segment);

            // 提取 播放总时长
            auto&& info = segment->FindChildById(EbmlElementId::Info);
            auto&& duration = info->FindChildById(EbmlElementId::Duration);
            this->duration = (float)std::stod(duration->value());

            // 提取 编码方式
            auto&& tracks = segment->FindChildById(EbmlElementId::Tracks);
            auto&& trackEntry = tracks->FindChildById(EbmlElementId::TrackEntry);
            auto&& codecId = trackEntry->FindChildById(EbmlElementId::CodecID);
            this->codecId = codecId->value() == "V_VP8" ? 0 : 1;

            // 提取 宽高
            auto&& video = trackEntry->FindChildById(EbmlElementId::Video);
            auto&& pixelWidth = video->FindChildById(EbmlElementId::PixelWidth);
            this->width = std::stoi(pixelWidth->value());
            auto&& pixelHeight = video->FindChildById(EbmlElementId::PixelHeight);
            this->height = std::stoi(pixelHeight->value());

            // 判断 是否带 alpha 通道
            auto&& _alphaMode = video->FindChildById(EbmlElementId::AlphaMode);
            this->hasAlpha = _alphaMode->value() == "1" ? 1 : 0;

            std::vector<int> frames;
            uint32_t frameNumber = 0;

            std::list<EbmlElement>::const_iterator clusterOwner;
            if (this->codecId == 0) {
                clusterOwner = segment;
            }
            else {
                auto&& tags = segment->FindChildById(EbmlElementId::Tags);
                auto&& tag = tags->FindChildById(EbmlElementId::Tag);
                clusterOwner = tag->FindChildById(EbmlElementId::Targets);
            }

            auto&& cluster = clusterOwner->FindChildById(EbmlElementId::Cluster);
            while (cluster != clusterOwner->children().cend()) {
                auto timecode = cluster->FindChildById(EbmlElementId::Timecode);
                auto clusterPts = std::stoi(timecode->value());

                if (this->hasAlpha) {
                    auto&& blockGroup = cluster->FindChildById(EbmlElementId::BlockGroup);
                    while (blockGroup != cluster->children().cend()) {
                        {
                            // get yuv data + size
                            auto&& block = blockGroup->FindChildById(EbmlElementId::Block);
                            auto&& data = block->data();
                            auto&& size = block->size();

                            // fix yuv data + size
                            size_t track_number_size_length;
                            (void)get_ebml_element_size(data, size, track_number_size_length);
                            data = data + track_number_size_length + 3;
                            size = size - track_number_size_length - 3;

                            this->lens.push_back((uint32_t)size);
                            this->data.insert(this->data.end(), data, data + size);
                        }
                        {
                            // get a data + size
                            auto&& blockAdditions = blockGroup->FindChildById(EbmlElementId::BlockAdditions);
                            auto&& blockMore = blockAdditions->FindChildById(EbmlElementId::BlockMore);
                            auto&& blockAdditional = blockMore->FindChildById(EbmlElementId::BlockAdditional);
                            auto&& data_alpha = blockAdditional->data();
                            auto&& size_alpha = (uint32_t)blockAdditional->size();

                            this->lens.push_back((uint32_t)size_alpha);
                            this->data.insert(this->data.end(), data_alpha, data_alpha + size_alpha);
                        }

                        // next
                        blockGroup = cluster->FindNextChildById(++blockGroup, EbmlElementId::BlockGroup);
                        ++frameNumber;
                    }
                }
                else {
                    auto&& simpleBlock = cluster->FindChildById(EbmlElementId::SimpleBlock);
                    while (simpleBlock != cluster->children().cend()) {
                        auto&& data = simpleBlock->data();
                        auto&& size = simpleBlock->size();

                        // fix yuv data + size
                        size_t track_number_size_length;
                        (void)get_ebml_element_size(data, size, track_number_size_length);
                        data = data + track_number_size_length + 3;
                        size = size - track_number_size_length - 3;

                        this->lens.push_back((uint32_t)size);
                        this->data.insert(this->data.end(), data, data + size);

                        // next
                        simpleBlock = cluster->FindNextChildById(++simpleBlock, EbmlElementId::BlockGroup);
                        ++frameNumber;
                    }
                }

                cluster = clusterOwner->FindNextChildById(++cluster, EbmlElementId::Cluster);
            }

            return Init();
        }


        void SkipFrame(int frame, vpx_codec_ctx_t& ctx, vpx_codec_ctx_t& ctxAlpha) {
            uint8_t const* rgbBuf = nullptr, * aBuf = nullptr;
            uint32_t rgbBufLen = 0, aBufLen = 0;
            if (this->hasAlpha) {
                if (int r = this->GetFrameBuf(frame, rgbBuf, rgbBufLen, aBuf, aBufLen)) assert(false);
                if (int r = vpx_codec_decode(&ctx, rgbBuf, rgbBufLen, nullptr, 0)) assert(false);
                if (int r = vpx_codec_decode(&ctxAlpha, aBuf, aBufLen, nullptr, 0)) assert(false);
            }
        }

        void DecodeFrame(std::vector<uint8_t>& bytes, int frame, vpx_codec_ctx_t& ctx, vpx_codec_ctx_t& ctxAlpha)
        {
            uint8_t const* rgbBuf = nullptr, * aBuf = nullptr;
            uint32_t rgbBufLen = 0, aBufLen = 0;

            if (this->hasAlpha) {
                if (int r = this->GetFrameBuf(frame, rgbBuf, rgbBufLen, aBuf, aBufLen)) assert(false);
                if (int r = vpx_codec_decode(&ctx, rgbBuf, rgbBufLen, nullptr, 0)) assert(false);
                if (int r = vpx_codec_decode(&ctxAlpha, aBuf, aBufLen, nullptr, 0)) assert(false);

                vpx_codec_iter_t iterator = nullptr;
                auto&& imgRGB = vpx_codec_get_frame(&ctx, &iterator);
                if (!imgRGB || imgRGB->fmt != VPX_IMG_FMT_I420) assert(false);
                if (imgRGB->stride[1] != imgRGB->stride[2]) assert(false);

                iterator = nullptr;
                auto&& imgA = vpx_codec_get_frame(&ctxAlpha, &iterator);
                if (!imgA || imgA->fmt != VPX_IMG_FMT_I420) assert(false);
                if (imgA->stride[0] != imgRGB->stride[0]) assert(false);

                if (int r = Yuva2Rgba(bytes, this->width, this->height
                        , imgRGB->planes[0], imgRGB->planes[1], imgRGB->planes[2], imgA->planes[0]
                        , imgRGB->stride[0], imgRGB->stride[1])) assert(false);
            }
            else {
                if (int r = this->GetFrameBuf(frame, rgbBuf, rgbBufLen)) assert(false);
                if (int r = vpx_codec_decode(&ctx, rgbBuf, rgbBufLen, nullptr, 0)) assert(false);

                vpx_codec_iter_t iterator = nullptr;
                auto&& imgRGB = vpx_codec_get_frame(&ctx, &iterator);
                if (!imgRGB || imgRGB->fmt != VPX_IMG_FMT_I420) assert(false);
                if (imgRGB->stride[1] != imgRGB->stride[2]) assert(false);

                if (int r = Yuva2Rgba(bytes, this->width, this->height
                        , imgRGB->planes[0], imgRGB->planes[1], imgRGB->planes[2], nullptr
                        , imgRGB->stride[0], imgRGB->stride[1])) assert(false);
            }
        }

        // f = [](std::vector<uint8_t> const& bytes)->int { ... }
        template<typename F>
        inline int ForeachFrame(F&& f) {
            vpx_codec_ctx_t ctx;
            vpx_codec_dec_cfg_t cfg{ 1, this->width, this->height };
            assert(this->codecId); //auto&& iface = this->codecId ? vpx_codec_vp9_dx() : vpx_codec_vp8_dx();
            auto&& iface = vpx_codec_vp9_dx();
//            auto&& iface = this->codecId ? vpx_codec_vp9_dx() : vpx_codec_vp8_dx();
            if (int r = vpx_codec_dec_init(&ctx, iface, &cfg, 0)) return __LINE__;	// VPX_CODEC_OK == 0
            auto sgCtx = MyScopeGuard([&] {
                vpx_codec_destroy(&ctx);
            });

            uint8_t const* rgbBuf = nullptr, * aBuf = nullptr;
            uint32_t rgbBufLen = 0, aBufLen = 0;
            std::vector<uint8_t> bytes;

            if (this->hasAlpha) {
                vpx_codec_ctx_t ctxAlpha;
                if (int r = vpx_codec_dec_init(&ctxAlpha, iface, &cfg, 0)) return __LINE__;
                auto sgCtxAlpha = MyScopeGuard([&] {
                    vpx_codec_destroy(&ctxAlpha);
                });

                auto timeStart = std::chrono::steady_clock::now();
                for (uint32_t i = 0; i < this->count; ++i) {
//                    auto time1 = std::chrono::steady_clock::now();
                    if (int r = this->GetFrameBuf(i, rgbBuf, rgbBufLen, aBuf, aBufLen)) return r;

                    if (int r = vpx_codec_decode(&ctx, rgbBuf, rgbBufLen, nullptr, 0)) return __LINE__;
//                    auto time11 = std::chrono::steady_clock::now();
                    if (int r = vpx_codec_decode(&ctxAlpha, aBuf, aBufLen, nullptr, 0)) return __LINE__;

//                    auto time2 = std::chrono::steady_clock::now();
                    vpx_codec_iter_t iterator = nullptr;
                    auto&& imgRGB = vpx_codec_get_frame(&ctx, &iterator);
                    if (!imgRGB || imgRGB->fmt != VPX_IMG_FMT_I420) return __LINE__;
                    if (imgRGB->stride[1] != imgRGB->stride[2]) return __LINE__;

//                    auto time3 = std::chrono::steady_clock::now();
                    iterator = nullptr;
                    auto&& imgA = vpx_codec_get_frame(&ctxAlpha, &iterator);
                    if (!imgA || imgA->fmt != VPX_IMG_FMT_I420) return __LINE__;
                    if (imgA->stride[0] != imgRGB->stride[0]) return __LINE__;

//                    auto time4 = std::chrono::steady_clock::now();
                    if (int r = Yuva2Rgba(bytes, this->width, this->height
                            , imgRGB->planes[0], imgRGB->planes[1], imgRGB->planes[2], imgA->planes[0]
                            , imgRGB->stride[0], imgRGB->stride[1])) return __LINE__;
//                    auto time5 = std::chrono::steady_clock::now();

                    if (int r = f(bytes, i)) return r;

//                    auto time6 = std::chrono::steady_clock::now();
//                    auto duration11 = std::chrono::duration_cast<std::chrono::microseconds>(time11 - time1);
//                    auto duration12 = std::chrono::duration_cast<std::chrono::microseconds>(time2 - time11);
//                    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(time2 - time1);
//                    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(time3 - time2);
//                    auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(time4 - time3);
//                    auto duration4 = std::chrono::duration_cast<std::chrono::microseconds>(time5 - time4);
//                    auto duration5 = std::chrono::duration_cast<std::chrono::microseconds>(time6 - time5);
//                    auto duration6 = std::chrono::duration_cast<std::chrono::microseconds>(time6 - time1);
//                    std::stringstream  ss;
//                    ss << "use time:" << i
//                            << ", " << duration11.count()
//                            << ", " << duration12.count()
//                            << ", " << duration1.count()
//                            << ", " << duration2.count()
//                            << ", " << duration3.count()
//                            << ", " << duration4.count()
//                            << ", " << duration5.count()
//                            << ", " << duration6.count()
//                            << std::endl;
//                    print_log(ss.str());
                }
                auto timeEnd = std::chrono::steady_clock::now();
                auto decodeDuration = std::chrono::duration_cast<std::chrono::microseconds>(timeEnd - timeStart);
                std::stringstream ss1;
                ss1 << "decode ues time:" << decodeDuration.count() << ", frame count: " << this->count;
                print_log(ss1.str());
            }
            else {
                for (uint32_t i = 0; i < this->count; ++i) {
                    if (int r = this->GetFrameBuf(i, rgbBuf, rgbBufLen)) return r;

                    if (int r = vpx_codec_decode(&ctx, rgbBuf, rgbBufLen, nullptr, 0)) return __LINE__;

                    vpx_codec_iter_t iterator = nullptr;
                    auto&& imgRGB = vpx_codec_get_frame(&ctx, &iterator);
                    if (!imgRGB || imgRGB->fmt != VPX_IMG_FMT_I420) return __LINE__;
                    if (imgRGB->stride[1] != imgRGB->stride[2]) return __LINE__;

                    if (int r = Yuva2Rgba(bytes, this->width, this->height
                            , imgRGB->planes[0], imgRGB->planes[1], imgRGB->planes[2], nullptr
                            , imgRGB->stride[0], imgRGB->stride[1])) return __LINE__;
                    if (int r = f(bytes, i)) return r;
                }
            }

            return 0;
        }

        inline static int Yuva2Rgba(std::vector<uint8_t>& bytes
                , uint32_t const& w, uint32_t const& h
                , uint8_t const* const& yData, uint8_t const* const& uData, uint8_t const* const& vData, uint8_t const* const& aData
                , uint32_t const& yaStride, uint32_t const& uvStride) {

#ifdef LIBYUV_API
            bytes.resize(w * h * 4);
			return libyuv::I420AlphaToABGR(yData, yaStride, uData, uvStride, vData, uvStride, aData, yaStride, bytes.data(), w * 4, w, h, 0);
#else
            // 这段代码逻辑可写入 shader
            bytes.clear();
            bytes.reserve(w * h * 4);

            // 产生像素坐标
            for (uint32_t _h = 0; _h < h; ++_h) {
                for (uint32_t _w = 0; _w < w; ++_w) {
                    // 根据坐标结合具体宽高跨距算下标. uv 每个像素对应 ya 4个像素
                    auto yaIdx = yaStride * _h + _w;
                    auto uvIdx = uvStride * (_h / 2) + _w / 2;

                    // 得到 yuv 原始数据, byte -> float
                    auto y = yData[yaIdx] / 255.0f;
                    auto u = uData[uvIdx] / 255.0f;
                    auto v = vData[uvIdx] / 255.0f;

                    // 进一步修正
                    y = 1.1643f * (y - 0.0625f);
                    u = u - 0.5f;
                    v = v - 0.5f;

                    // 算出 rgb( float 版 )
                    auto r = y + 1.5958f * v;
                    auto g = y - 0.39173f * u - 0.81290f * v;
                    auto b = y + 2.017f * u;

                    // 裁剪为 0 ~ 1
                    if (r > 1.0f) r = 1.0f; else if (r < 0.0f) r = 0.0f;
                    if (g > 1.0f) g = 1.0f; else if (g < 0.0f) g = 0.0f;
                    if (b > 1.0f) b = 1.0f; else if (b < 0.0f) b = 0.0f;

                    // 存起来
                    bytes.push_back((uint8_t)(r * 255));
                    bytes.push_back((uint8_t)(g * 255));
                    bytes.push_back((uint8_t)(b * 255));
                    bytes.push_back(aData ? aData[yaIdx] : (uint8_t)0);
                }
            }
            return 0;
#endif
        }

        // 将 srcPos(小图) 绘制 到 dstPos(大图) 的 x,y (bmp左上角). 因为是图片打包用途，故必须确保 space 装得下, 没有边缘问题
        // 先计算第一行第一个像素 要从 space 的哪个下标 开始填, 每次填 bw 长, 填完后 下标 += sw 填 bh 次
        inline static void Draw(uint32_t* dstPos, uint32_t const& sw, uint32_t const& sh
                , uint32_t* srcPos, uint32_t const& bw, uint32_t const& bh, uint32_t const& x, uint32_t const& y) {
            assert(x >= 0 && y >= 0 && x + bw < sw&& y + bh < sh);
            dstPos += sw * y + x;
            auto dstPosEnd = dstPos + sw * bh;
            auto copyLen = bw * sizeof(uint32_t);
            for (; dstPos < dstPosEnd; dstPos += sw) {
                memcpy(dstPos, srcPos, copyLen);
                srcPos += bw;
            }
        }
    };
}
