#ifndef __PAIGOW_SNAPTSHOT_H__
#define __PAIGOW_SNAPTSHOT_H__
#include "games/MatchSnapshot.h"
#include "games/paigow/PaiGowLogic.h"
#include "games/paigow/PaiGowPlayer.h"
#include <map>



NS_PAIGOW_BEGIN
enum class TableState;
class PaiGowSnaptShot:public game::MatchSnaptShot
{
public:
	PaiGowSnaptShot();
	virtual ~PaiGowSnaptShot();
public:
	void init(const proto3_proto::S2C_MatchSnapshot& mc_st);
	void addPlayer(const proto3_proto::PaiGowPlayer& p);
	int getSeatIndex(int seatid);
	PaiGowPlayer* getMainPlayer() const;

public:
	TableState table_state;
	//TableState table_state;					//牌桌状态
	uint32_t room_owner; 					//牌桌拥有者
	Card* public_cards;							//公牌
	std::map<uint32_t,PaiGowPlayer*> players;						//牌九玩家
	//repeated PaiGowResult results = 5; 			//本局当前比赛结果
};


NS_PAIGOW_END
#endif // !__PAIGOW_SNAPTSHOT_H__

