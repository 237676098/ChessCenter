#ifndef __PAIGOW_PLAYER_H__
#define __PAIGOW_PLAYER_H__
#include "PaiGowLogic.h"
#include "games/PlayerInfo.h"

NS_PAIGOW_BEGIN

class PaiGowPlayer:public game::PlayerInfo
{
public:
	PaiGowPlayer();
	~PaiGowPlayer();
private:
	Card* m_hand_cards;
	bool m_is_banker;

};


NS_PAIGOW_END

#endif