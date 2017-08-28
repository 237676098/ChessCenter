#include "TableState.h"
#include "games/game.h"


NS_CORE_BEGIN

GAME_STATE TableState::handleEvent(const GameEvent * event)
{
	if (false)
	{

	}
	else
	{
		return STATE_LOBBY;
	}
}

void TableState::enter(const GameEvent* event)
{
	if (event->getType() == EVENT_TABLE_SNAPTSHOT)
	{
		GameSnaptshotEvent* ptr = dynamic_cast<GameSnaptshotEvent*>(const_cast<GameEvent*>(event));
		game::GameManager::getInstance()->init(ptr->getSnaptShot());
	}
	
}

void TableState::exit(const GameEvent* event)
{
	game::GameManager::getInstance()->dispose();
}



NS_CORE_END

