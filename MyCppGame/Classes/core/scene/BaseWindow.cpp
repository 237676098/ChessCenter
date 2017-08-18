#include "BaseWindow.h"
#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"
USING_NS_CC;
NS_CORE_BEGIN
IBaseWindow::IBaseWindow(std::string path,bool is_black,bool is_full_screen)
	:m_s_path(path),
	m_b_is_black(is_black), 
	m_b_is_full_screen(is_full_screen)
{
	initCSB();
}

IBaseWindow::~IBaseWindow()
{
}

void IBaseWindow::initCSB()
{
	setCascadeOpacityEnabled(true);
	if (m_b_is_black)
	{
		m_layer_bg = cocos2d::LayerColor::create(cocos2d::Color4B(0, 0, 0, 180));
	}else
	{
		m_layer_bg = cocos2d::LayerColor::create(cocos2d::Color4B(0, 0, 0, 0));
	}
	auto listener = cocos2d::EventListenerTouchOneByOne::create();
	
	listener->onTouchBegan = [](Touch *touch, Event *event)->bool {
		//CCLOG("touch window bg");
		return true;
	};
	listener->onTouchCancelled = [](Touch *touch, Event *event)->bool {
		//CCLOG("touch window bg");
		return true;
	};
	listener->onTouchMoved = [](Touch *touch, Event *event)->bool {
		//CCLOG("touch window bg");
		return true;
	};
	listener->onTouchEnded = [](Touch *touch, Event *event)->bool {
		CCLOG("touch window bg");
		return true;
	};
	listener->setSwallowTouches(true);
	m_layer_bg->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, m_layer_bg);
	addChild(m_layer_bg);

	//widgetFromBinaryFile
	std::string fullPath = "csb/" + m_s_path + ".csb";
	m_node_csb = CSLoader::createNode(fullPath);
	//CCASSERT(m_widget_csb, std::string("create base widget from ").append(fullPath.c_str()).append(" failed!").c_str());
	this->setContentSize(m_node_csb->getContentSize());
	this->addChild(m_node_csb);
	if (m_b_is_full_screen)
	{
		setContentSize(cocos2d::Director::getInstance()->getWinSize());
		m_node_csb->setContentSize(cocos2d::Director::getInstance()->getWinSize());
		cocos2d::ui::Helper::doLayout(m_node_csb);
	}

	onLoadCompleted();
}
void IBaseWindow::onLoadCompleted()
{
	Button* closeBtn = m_node_csb->getChildByName<Button*>("m_btn_close");
	if (closeBtn)
	{
		closeBtn->addClickEventListener(std::bind(&IBaseWindow::onClickBtn, this, std::placeholders::_1));
	}
}
void IBaseWindow::onClickBtn(Ref* btn)
{
}
NS_CORE_END