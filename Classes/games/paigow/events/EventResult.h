#ifndef __EVENT_RESULT_H__
#define __EVENT_RESULT_H__
#include "core/event/EventManager.h"
#include "core/network/socket/protocol.h"

NS_PAIGOW_BEGIN

class EventResult :public core::Event
{
public:
	EventResult() : Event(core::EVT_PG_Result) {};

public:
	proto3_proto::S2C_PG_Result* result;
};


NS_PAIGOW_END


#endif