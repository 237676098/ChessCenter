#ifndef __PAIGOW_SNAPTSHOT_H__
#define __PAIGOW_SNAPTSHOT_H__
#include "games/MatchSnapshot.h"
#include "games/paigow/PaiGowLogic.h"
#include "games/paigow/PaiGowPlayer.h"
#include <map>
#include <vector>
#include "PaiGowResult.h"



NS_PAIGOW_BEGIN
enum class TableState;
class PaiGowSnaptShot:public game::MatchSnaptShot
{
public:
	PaiGowSnaptShot();
	virtual ~PaiGowSnaptShot();
public:
	void init(const proto3_proto::S2C_MatchSnapshot& mc_st);
	void clear();
	void addPlayer(const proto3_proto::PaiGowPlayer& p);
	void deletePlayer(uint32_t seatid);
	int getSeatIndex(int seatid) const;
	PaiGowPlayer* getMainPlayer() const;
	bool isMainPlayer(uint32_t seat_id) const;
	bool isBanker(uint32_t seat_id) const;
	void updatePlayerState(uint32_t seat_id, PlayerStatus status);
	void updatePlayerState(PlayerStatus status);

public:
	void clearResult();
	void addResult(const proto3_proto::PaiGowResult& result);

public:
	TableState table_state;
	uint32_t room_owner; 					//牌桌拥有者
	uint32_t banker_seat_id;				//庄家位
	std::vector<Card> public_cards;							//公牌
	std::map<uint32_t,PaiGowPlayer*> players;						//牌九玩家
	std::vector<PaiGowResult*> results;
};


NS_PAIGOW_END
#endif // !__PAIGOW_SNAPTSHOT_H__

