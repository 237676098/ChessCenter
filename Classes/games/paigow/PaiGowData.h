#ifndef __PAIGOW_DATA_H__
#define __PAIGOW_DATA_H__
#include "PaiGowLogic.h"
#include "PaiGowSnapshot.h"

NS_PAIGOW_BEGIN

class PaiGowProxy;

class PaiGowData
{
public:
	PaiGowData();
	~PaiGowData();

public:
	void updatePlayerState(uint32_t seat_id, PlayerStatus status);
	void updatePlayerState(PlayerStatus status);

private:
	friend class PaiGowProxy;
	PaiGowSnaptShot* pg_st;
};


NS_PAIGOW_END

#endif