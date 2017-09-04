#ifndef __EVENT_GRAB_STATUS_H__
#define __EVENT_GRAB_STATUS_H__
#include "core/event/EventManager.h"

NS_PAIGOW_BEGIN

class EventGrabStatus :public core::Event
{
public:
	EventGrabStatus(uint32_t s_id,bool grab):
		seat_id(s_id),
		is_grab(grab),
		Event(core::EVT_PG_GrabStatus) {};

public:
	uint32_t seat_id;
	bool is_grab;
};


NS_PAIGOW_END


#endif