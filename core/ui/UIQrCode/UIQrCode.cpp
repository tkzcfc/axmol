#include "ui/UIQrCode/UIQrCode.h"
#include "QrEncode/qrencode.h"
#include "QrEncode/qrspec.h"
#include "ui/UIScale9Sprite.h"

namespace ax
{

namespace ui
{

QrCode* QrCode::create(const std::string& code, int level)
{
    QrCode* qr = new (std::nothrow) QrCode();
    if (qr && qr->initQr(code, level))
    {
        qr->autorelease();
        return qr;
    }
    AX_SAFE_DELETE(qr);
    return nullptr;
}

QrCode* QrCode::create()
{
    QrCode* qr = new (std::nothrow) QrCode();
    if (qr && qr->init()) {
        qr->autorelease();
        return qr;
    }
    AX_SAFE_DELETE(qr);
    return nullptr;
}

Widget* QrCode::createCloneInstance()
{
    return QrCode::create();
}

void QrCode::copySpecialProperties(Widget* widget)
{
    ImageView::copySpecialProperties(widget);
    QrCode* qr = dynamic_cast<QrCode*>(widget);
    if (qr) {
        qr->originSize         = originSize;
    }
}

bool QrCode::initQr(const std::string& code, int level)
{
    return init() && loadCodeByString(code, level);
}

bool QrCode::loadCodeByString(const std::string& code, int level)
{
    level           = std::clamp(level, (int)QR_ECLEVEL_L, (int)QR_ECLEVEL_H);
    bool flag = false;
    QRcode* _qrcode = QRcode_encodeString(code.c_str(), 0, (QRecLevel)level, QR_MODE_8, 1);

    if (_qrcode) {
        const int width = _qrcode->width;
        auto data = new unsigned char[static_cast<size_t>(width) * width * 4];
        //White by default
        memset(data, 255, static_cast<size_t>(width) * width * 4);

        for (int i = 0; i < _qrcode->width; ++i) {
            for (int j = 0; j < _qrcode->width; ++j) {
                if ((_qrcode->data[i * _qrcode->width + j] & 1) == 1) {
                    data[i * _qrcode->width * 4 + j * 4]          = 0;  // r
                    data[i * _qrcode->width * 4 + j * 4 + 1]      = 0;  // g
                    data[i * _qrcode->width * 4 + j * 4 + 2]      = 0;  // b
                }
            }
        }
        Image* image = new Image();
        if (image->initWithRawData(data, static_cast<ssize_t>(width) * width, width, width, 0, false))
        {
            auto key = fmt::format("/@QrKey:{}", fmt::ptr(this));
            auto texture = _director->getTextureCache()->addImage(image, key);
            if (texture)
            {
                texture->setAliasTexParameters();
                auto frame = SpriteFrame::createWithTexture(texture, Rect(0, 0, width, width));
                if (frame)
                {
                    flag = true;
                    this->loadTexture(frame);
                }
                _director->getTextureCache()->removeTexture(texture);
            }
        }
        AX_SAFE_RELEASE_NULL(image);
        delete[] data;

        originSize = width;
        QRcode_free(_qrcode);
    }
    return flag;
}

void QrCode::setOriginSize()
{
    setContentSize(Size(originSize,originSize));
}

int QrCode::getOriginSize()
{
    return originSize;
}

}  // namespace ui
}  // namespace ax
