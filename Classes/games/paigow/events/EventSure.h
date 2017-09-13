#ifndef __EVENT_SURE_H__
#define __EVENT_SURE_H__
#include "core/event/EventManager.h"

NS_PAIGOW_BEGIN

class EventSure :public core::Event
{
public:
	EventSure() : Event(core::EVT_PG_Sure) {};

public:
	uint32_t seat_id;
};


NS_PAIGOW_END


#endif