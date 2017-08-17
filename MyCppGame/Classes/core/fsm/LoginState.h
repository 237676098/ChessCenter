#pragma once
#include "IGameState.h"
NS_CORE_BEGIN
class LoginState :public IGameState
{
public:
	LoginState() :IGameState(STATE_LOGIN) {};
	void init();
private:

};
NS_CORE_END
