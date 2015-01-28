//
//  NativeBridge.cpp
//  SuperLife
//
//  Created by wang haibo on 15/1/27.
//
//

#include "NativeBridge.h"
USING_NS_CC;
static NativeBridge *s_NativeBridge = nullptr;
NativeBridge::NativeBridge()
{
}
NativeBridge* NativeBridge::getInstance()
{
    if (! s_NativeBridge)
    {
        s_NativeBridge = new NativeBridge();
    }
    
    return s_NativeBridge;
}
NativeBridge::~NativeBridge()
{
}
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
void NativeBridge::setRootViewController(RootViewController* viewController)
{
    mViewController = viewController;
}
#endif
void NativeBridge::showAdsView()
{
    CCLOG("showAdsView");
    //return;
    if(mViewController != nil)
        [mViewController showAdsView];
}
void NativeBridge::hideAdsView()
{
    CCLOG("hideAdsView");
    if(mViewController != nil)
        [mViewController hideAdsView];
}
void NativeBridge::showRateAppView()
{
    CCLOG("showRateAppView");
    if(mViewController != nil)
    {
        LanguageType lt= CCApplication::getInstance()->getCurrentLanguage();
        switch (lt) {
            case LanguageType::CHINESE:
                [mViewController showRateAppViewCH];
                break;
                
            default:
                [mViewController showRateAppViewEN];
                break;
        }
    }
}