#include "LobbyState.h"
#include "lobby/lobby.h"


NS_CORE_BEGIN

GAME_STATE LobbyState::handleEvent(const GameEvent * event)
{
	if (event->getType() == EVENT_TABLE_SNAPTSHOT)
	{
		return STATE_TABLE;
	}
	else
	{
		return STATE_LOBBY;
	}
}

void LobbyState::enter(const GameEvent* event)
{
	lobby::LobbyManager::getInstance()->init();
}

void LobbyState::exit(const GameEvent* event)
{
	lobby::LobbyManager::getInstance()->dispose();
}



NS_CORE_END


