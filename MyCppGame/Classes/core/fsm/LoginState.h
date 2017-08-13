#pragma once
#include "IGameState.h"

class LoginState:public IGameState
{
public:
	LoginState():IGameState(STATE_LOGIN) {};

private:

};
