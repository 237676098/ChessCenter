#include "BaseWindow.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "WindowManager.h"
USING_NS_CC;
NS_CORE_BEGIN
IBaseWindow::IBaseWindow(std::string path,bool is_black,bool is_full_screen)
	:m_s_path(path),
	m_b_is_black(is_black), 
	m_b_is_full_screen(is_full_screen)
{
	
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
	listener->onTouchCancelled = [](Touch *touch, Event *event)->void {
		//CCLOG("touch window bg");
	};
	listener->onTouchMoved = [](Touch *touch, Event *event)->void {
		//CCLOG("touch window bg");
	};
	listener->onTouchEnded = [](Touch *touch, Event *event)->void {
		CCLOG("touch window bg");
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

	Button* closeBtn = m_node_csb->getChildByName<Button*>("m_btn_close");
	if (closeBtn)
	{
		closeBtn->addClickEventListener(std::bind(&IBaseWindow::onClickCloseBtn, this, std::placeholders::_1));
	}

	if (m_node_csb->getChildByName("center_node"))
	{
		auto btn = m_node_csb->getChildByName("center_node")->getChildByName<Button*>("btn_close");
		if (btn)
		{
			btn->addClickEventListener(std::bind(&IBaseWindow::onClickCloseBtn, this, std::placeholders::_1));
		}
	}

	Node* center = m_node_csb->getChildByName<Node*>("center");
	if (center)
	{
		Button* closeBtn = center->getChildByName<Button*>("m_btn_close");
		if (closeBtn)
		{
			closeBtn->addClickEventListener(std::bind(&IBaseWindow::onClickCloseBtn, this, std::placeholders::_1));
		}
	}

	

	onLoadCompleted();
}

void IBaseWindow::onLoadCompleted()
{

}

void IBaseWindow::onClickCloseBtn(Ref* btn)
{
	//WindowManager::getInstance()->close();
}
NS_CORE_END