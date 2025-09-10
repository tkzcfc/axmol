
#pragma once

#include "ui/UIImageView.h"
#include "ui/GUIExport.h"

namespace ax
{
namespace ui
{
class AX_GUI_DLL QrCode : public ImageView
{
    public:
        static QrCode* create(const std::string& code, int level = 1);
        static QrCode* create();
        bool loadCodeByString(const std::string& code, int level = 1);
        void setOriginSize();
        int getOriginSize();
    protected:
        Widget* createCloneInstance() override;
        void copySpecialProperties(Widget* model) override;

        virtual bool initQr(const std::string& code, int level);
        
    protected:
        int originSize = 0;
};
}  // namespace ui
}  // namespace ax
