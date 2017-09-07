#ifndef __EVENT_DEAL_CARD_H__
#define __EVENT_DEAL_CARD_H__
#include "core/event/EventManager.h"

NS_PAIGOW_BEGIN

class EventDealCard :public core::Event
{
public:
	EventDealCard() : Event(core::EVT_PG_DealCard) {};

public:
	std::map<uint32_t, std::vector<Card>> hand_cards;
};


NS_PAIGOW_END


#endif