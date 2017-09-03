#ifndef __EVENT_OFF_LINE_H__
#define __EVENT_OFF_LINE_H__
#include "core/event/EventManager.h"


NS_PAIGOW_BEGIN

class EventOffline:public core::Event
{
public:
	EventOffline(uint32_t s_id,bool ol) :seat_id(s_id),offline(ol),Event(core::EVT_PG_OffLine) {};

public:
	uint32_t seat_id;
	bool offline;
};


NS_PAIGOW_END

#endif