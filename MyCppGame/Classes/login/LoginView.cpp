#include "LoginView.h"
#include "ui\UIButton.h"
#include "socket\SocketManager.h"
using namespace cocos2d::ui;
NS_LOGIN_BEGIN

LoginView * LoginView::create()
{
	LoginView* loginView = new (std::nothrow) LoginView();
	if (loginView && loginView->init())
	{
		loginView->autorelease();
		loginView->initWithFile("login");
		return loginView;
	}
	CC_SAFE_DELETE(loginView);
	return nullptr;
}


bool LoginView::initWithFile(const std::string fileName)
{
	if (!IBaseUI::initWithFile(fileName))
	{
		return false;
	}
	Button* loginBtn= dynamic_cast<Button*>(m_csb->getChildByName("center")->getChildByName("Button_1"));
	loginBtn->addClickEventListener(std::bind(&LoginView::onLoginBtnClick,this,std::placeholders::_1));
	loginBtn->setPressedActionEnabled(true);
	loginBtn->setZoomScale(0.04);
	return true;
}

void LoginView::onLoginBtnClick(Ref* btn)
{
	core::SocketManager::getInstance()->connect("47.94.95.187", "1008");
}

NS_LOGIN_END