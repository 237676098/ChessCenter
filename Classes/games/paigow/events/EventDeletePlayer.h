#ifndef __EVENT_DELETE_PLAYER_H__
#define __EVENT_DELETE_PLAYER_H__
#include "core/event/EventManager.h"

NS_PAIGOW_BEGIN

class EventDeletePlayer :public core::Event
{
public:
	EventDeletePlayer(uint32_t s_id) :seat_id(s_id), Event(core::EVT_PG_DeletePlayer) {};

public:
	uint32_t seat_id;
};


NS_PAIGOW_END


#endif