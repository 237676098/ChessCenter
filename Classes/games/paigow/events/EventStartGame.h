#ifndef __EVENT_START_GAME_H__
#define __EVENT_START_GAME_H__
#include "core/event/EventManager.h"

NS_PAIGOW_BEGIN

class EventStartGame :public core::Event
{
public:
	EventStartGame() : Event(core::EVT_PG_StartGame) {};

public:
	
};


NS_PAIGOW_END


#endif