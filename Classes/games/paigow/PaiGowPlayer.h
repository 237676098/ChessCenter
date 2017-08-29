#ifndef __PAIGOW_PLAYER_H__
#define __PAIGOW_PLAYER_H__
#include "PaiGowLogic.h"
#include "games/PlayerInfo.h"
#include <stdint.h>

NS_PAIGOW_BEGIN

class PaiGowPlayer :public game::PlayerInfo
{
public:
	PaiGowPlayer();
	virtual  ~PaiGowPlayer();
	void initByPaiGowPlayer(const proto3_proto::PaiGowPlayer& player);
public:
	bool is_banker;
	bool status;
	Card* hand_cards;
	uint32_t* chips;
};


NS_PAIGOW_END

#endif