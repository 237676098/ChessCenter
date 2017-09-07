#ifndef __EVENT_COLLOCATION_H__
#define __EVENT_COLLOCATION_H__
#include "core/event/EventManager.h"
#include "games/paigow/PaiGowLogic.h"
#include <vector>

NS_PAIGOW_BEGIN

class EventCollocation :public core::Event
{
public:
	EventCollocation():Event(core::EVT_PG_Collocation) {};

public:
	uint32_t seat_id;
	std::vector<Card> cards;
};


NS_PAIGOW_END


#endif