#include "LoginState.h"
#include "login\login.h"

NS_CORE_BEGIN

void LoginState::init()
{
	login::LoginManager::getInstance()->init();
}

NS_CORE_END


