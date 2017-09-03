#ifndef __EVENT_BANKER_CONFIRM_H__
#define __EVENT_BANKER_CONFIRM_H__

#include "core/event/EventManager.h"

NS_PAIGOW_BEGIN

class EventBankerConfirm :public core::Event
{
public:
	EventBankerConfirm(uint32_t s_id) :seat_id(s_id), Event(core::EVT_PG_BankerConfirm) {};

public:
	uint32_t seat_id;
};


NS_PAIGOW_END

#endif