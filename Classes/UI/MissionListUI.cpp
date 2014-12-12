//
//  MissionListUI.cpp
//  SuperLife
//
//  Created by wang haibo on 14-8-19.
//
//

#include "MissionListUI.h"
#include "SceneFactory.h"
#include "UIMgr.h"
#include "GameConst.h"
USING_NS_CC;

// 构造函数
MissionListUI::MissionListUI(BaseScene* owner)
{
    m_pOwnerScene = nullptr;
    m_pLabelLevelSelect = nullptr;
    m_pScrollView = nullptr;
    m_pBackBtn = nullptr;
}
// 析构函数
MissionListUI::~MissionListUI()
{
}
// 加载文件
void MissionListUI::loadUI(const std::string& file)
{
    Color3B color = SceneFactory::getInstance()->getSceneColor();
    m_pLabelLevelSelect = Label::createWithTTF("关卡选择", "FZXS12.TTF", 120);
    m_pLabelLevelSelect->setPosition(Vec2(480,590));
    m_pLabelLevelSelect->setColor(color);
    m_pLabelLevelSelect->setScale(0.5f);
    this->addChild(m_pLabelLevelSelect);
    
    int ContainerHeight = (MAX_LEVEL/7)*110;
    m_pScrollView = ui::ScrollView::create();
    m_pScrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
    m_pScrollView->setContentSize(Size(960,440));
    m_pScrollView->setInnerContainerSize(Size(960,ContainerHeight));
    m_pScrollView->setPosition(Vec2(0,100));
    m_pScrollView->setTouchEnabled(true);
    
    
    for(int i = 1; i <=MAX_LEVEL; i++)
    {
        int k = i%7;
        int j = i/7;
        if(k==0)
        {
            k=7;
            j-=1;
        }
        
        Vec2 pos = Vec2(k*120,ContainerHeight-((j+1)*100-40));
        ui::Button* btn = ui::Button::create("levelBtnLBN.png","levelBtnLBD.png","levelBtnLBN.png");
        btn->setPosition(pos);
        btn->setTitleFontName("FZXS12.TTF");
        btn->setTitleColor(color);
        btn->setTitleFontSize(60);
        btn->setColor(color);
        btn->addTouchEventListener(CC_CALLBACK_2(MissionListUI::pressLevelSelectBtn, this));
        if( i > CUR_LEVEL)
        {
            btn->setTitleText("?");
            btn->setTouchEnabled(false);
            btn->setOpacity(100);
        }
        else
        {
            Value value = Value(CUR_LEVEL);
            btn->setTitleText(value.asString());
            btn->setTouchEnabled(true);
            btn->setOpacity(255);
        }
        btn->setTag(i);
        m_pScrollView->addChild(btn);
    }
    this->addChild(m_pScrollView);
}
//设置UI颜色
void MissionListUI::setColor(const cocos2d::Color3B& color)
{
}
// 点击返回按钮
void MissionListUI::pressLevelSelectBtn(Ref* p,TouchEventType eventType)
{
    if(eventType != TouchEventType::ENDED)
        return;
    ui::Button* btn = static_cast<ui::Button*>(p);
    if(btn)
    {
        BaseScene* missionScene = SceneFactory::getInstance()->createSceneByID(SCENE_MISSION);
        Director::getInstance()->replaceScene(missionScene);
    }
}
// 点击返回按钮
void MissionListUI::pressBackBtn(Ref* p,TouchEventType eventType)
{
}