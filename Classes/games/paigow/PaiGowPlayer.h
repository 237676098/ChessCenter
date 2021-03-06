#ifndef __PAIGOW_PLAYER_H__
#define __PAIGOW_PLAYER_H__
#include "PaiGowLogic.h"
#include "games/PlayerInfo.h"
#include <stdint.h>

NS_PAIGOW_BEGIN

enum PlayerStatus
{

	PLAYER_STATUS_READY = 0,
	PLAYER_STATUS_PREBANKER = 1,
	PLAYER_STATUS_AFTBANKER = 2,
	PLAYER_STATUS_PREBET = 3,
	PLAYER_STATUS_AFTBET = 4,
	
	PLAYER_STATUS_PRECOMPARE = 5,
	PLAYER_STATUS_AFTCOMPARE = 6,
	PLAYER_STATUS_PRESURE = 7,
	PLAYER_STATUS_AFTERSURE = 8,
};

class PaiGowPlayer :public game::PlayerInfo
{
public:
	PaiGowPlayer();
	virtual  ~PaiGowPlayer();
	void initByPaiGowPlayer(const proto3_proto::PaiGowPlayer& player);
	void reset();
public:
	uint32_t status;
	std::vector<Card> hand_cards;
	std::vector<uint32_t> chips;
	int score;
	bool is_grab;
	bool has_people;
};


NS_PAIGOW_END

#endif