#include "LobbyView.h"
#include "ui\UIButton.h"
#include "socket\SocketManager.h"
#include "core\scene\scene.h"
using namespace cocos2d::ui;
NS_LOBBY_BEGIN

LobbyView * LobbyView::create()
{
	LobbyView* lobbyView = new (std::nothrow) LobbyView();
	if (lobbyView && lobbyView->init())
	{
		lobbyView->autorelease();
		lobbyView->initWithFile("lobby");
		return lobbyView;
	}
	CC_SAFE_DELETE(lobbyView);
	return nullptr;
}


bool LobbyView::initWithFile(const std::string fileName)
{
	if (!IBaseUI::initWithFile(fileName))
	{
		return false;
	}

	/*
	Button* loginBtn = dynamic_cast<Button*>(m_csb->getChildByName("center")->getChildByName("Button_1"));
	loginBtn->addClickEventListener(std::bind(&LobbyView::onLoginBtnClick, this, std::placeholders::_1));
	loginBtn->setPressedActionEnabled(true);
	loginBtn->setZoomScale(0.04f);
	*/
	return true;
}

NS_LOBBY_END