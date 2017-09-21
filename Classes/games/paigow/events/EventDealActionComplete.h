#ifndef __EVENT_DEAL_ACTION_COMPLETE_H__
#define __EVENT_DEAL_ACTION_COMPLETE_H__
#include "core/event/EventManager.h"

NS_PAIGOW_BEGIN

class EventDealActionComplete :public core::Event
{
public:
	EventDealActionComplete() : Event(core::EVT_PG_DealActionComplete) {};

public:
	uint32_t seat_id;
	std::vector<Card> hand_cards;
};


NS_PAIGOW_END


#endif