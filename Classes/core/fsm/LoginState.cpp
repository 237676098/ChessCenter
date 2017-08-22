#include "LoginState.h"
#include "login\login.h"

NS_CORE_BEGIN

GAME_STATE LoginState::handleEvent(const GameEvent & event)
{
	if ((event.getType() == EVENT_USER_INFO_INITED_SUCCESS))
	{
		return STATE_LOBBY;
	}
	else
	{
		return STATE_LOGIN;
	}
}

void LoginState::init()
{
	login::LoginManager::getInstance()->init();
}

void LoginState::enter()
{
	login::LoginManager::getInstance()->enter();
}

void LoginState::exit()
{
	login::LoginManager::getInstance()->exit();
}

NS_CORE_END


