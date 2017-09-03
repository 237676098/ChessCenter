#ifndef __EVENT_BET_H__
#define __EVENT_BET_H__
#include "core/event/EventManager.h"

NS_PAIGOW_BEGIN

class EventBet :public core::Event
{
public:
	EventBet(uint32_t s_id, uint32_t b1, uint32_t b2)
		:seat_id(s_id),
		bet1(b1),
		bet2(b2),
		Event(core::EVT_PG_Bet) {};

public:
	uint32_t seat_id;
	uint32_t bet1;
	uint32_t bet2;
};


NS_PAIGOW_END


#endif