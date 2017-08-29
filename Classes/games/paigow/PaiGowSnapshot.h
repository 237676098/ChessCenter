#ifndef __PAIGOW_SNAPTSHOT_H__
#define __PAIGOW_SNAPTSHOT_H__
#include "games/MatchSnapshot.h"
#include "games/paigow/PaiGowLogic.h"
#include "games/paigow/PaiGowPlayer.h"

NS_PAIGOW_BEGIN

class PaiGowSnaptShot:public game::MatchSnaptShot
{
public:
	PaiGowSnaptShot();
	virtual ~PaiGowSnaptShot();
public:
	void init(const proto3_proto::S2C_MatchSnapshot& mc_st);

public:
	uint32_t table_state;					//牌桌状态
	uint32_t room_owner; 					//牌桌拥有者
	Card* public_cards;							//公牌
	PaiGowPlayer* players;						//牌九玩家
	//repeated PaiGowResult results = 5; 			//本局当前比赛结果
};


NS_PAIGOW_END
#endif // !__PAIGOW_SNAPTSHOT_H__

