#ifndef __LOGIN_STATE_H__
#define __LOGIN_STATE_H__
#include "IGameState.h"
NS_CORE_BEGIN
class LoginState :public IGameState
{
public:
	LoginState() :IGameState(STATE_LOGIN) {};
	GAME_STATE handleEvent(const GameEvent& event) override;
	void init() override;
	void enter() override;
	void exit() override;
private:

};
NS_CORE_END
#endif
