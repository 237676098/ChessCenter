#ifndef __LOBBY_STATE_H__
#define __LOBBY_STATE_H__
#include "IGameState.h"
NS_CORE_BEGIN
class LobbyState :public IGameState
{
public:
	LobbyState() :IGameState(STATE_LOBBY) {};
	GAME_STATE handleEvent(const GameEvent* event) override;
	void enter(const GameEvent* event) override;
	void exit(const GameEvent* event) override;
private:

};
NS_CORE_END
#endif
