#include "TableState.h"
#include "games/game.h"


NS_CORE_BEGIN

GAME_STATE TableState::handleEvent(const GameEvent & event)
{
	if (false)
	{

	}
	else
	{
		return STATE_LOBBY;
	}
}

void TableState::enter()
{
	game::paigow::PaigowManager::getInstance()->init();
}

void TableState::exit()
{
	game::paigow::PaigowManager::getInstance()->dispose();
}



NS_CORE_END


