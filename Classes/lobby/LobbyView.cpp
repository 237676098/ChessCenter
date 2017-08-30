#include "LobbyView.h"
#include "core/network/socket/SocketManager.h"
#include "core/scene/scene.h"
#include "modules/room/RoomCreateWindow.h"
#include "modules/room/RoomJoinWindow.h"
#include "core/fsm/game_machine.h"
#include "games/GameManager.h"
#include "user/UserManager.h"

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


	Button* joinRoomBtn = dynamic_cast<Button*>(m_csb->getChildByName("btn_join_room"));
	joinRoomBtn->addClickEventListener([](Ref*)->void {
		core::WindowManager::getInstance()->open<lobby::RoomJoinWindow>();
	});
	
	Button* createRoomBtn = dynamic_cast<Button*>(m_csb->getChildByName("btn_create_room"));
	createRoomBtn->addClickEventListener([](Ref*)->void {
		//core::WindowManager::getInstance()->open<lobby::RoomCreateWindow>();
		//core::GameSnaptshotEvent event;
		//core::UserInfoInitedEvent event;
		//core::GameStateMachine::getInstance()->dispatchEvent(&event);
		game::GameManager::getInstance()->createMatch();
	});

	//刷新大厅信息
	m_csb->getChildByName("left_top")->getChildByName<Text*>("tf_card")->setString(std::to_string(user::UserManager::getInstance()->getCard()));
	m_csb->getChildByName("left_top")->getChildByName<Text*>("tf_user_name")->setString(user::UserManager::getInstance()->getName());
	m_csb->getChildByName("left_top")->getChildByName<Text*>("tf_user_id")->setString("ID:" + std::to_string(user::UserManager::getInstance()->getId()));

	return true;
}

NS_LOBBY_END