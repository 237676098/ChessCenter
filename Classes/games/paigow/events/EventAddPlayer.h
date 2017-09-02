#include "core/event/EventManager.h"
#include "games/paigow/PaiGowPlayer.h"

NS_PAIGOW_BEGIN

class EventAddPlayer:public core::Event
{
public:
	EventAddPlayer(PaiGowPlayer* p, int id) :player(p), Event(id) {};

public:
	PaiGowPlayer* player;
};


NS_PAIGOW_END
