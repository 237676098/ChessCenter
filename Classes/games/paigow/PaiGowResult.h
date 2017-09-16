#ifndef __PAIGOW_RESULT_H__
#define __PAIGOW_RESULT_H__
#include "core/network/socket/SocketManager.h"
#include <stdint.h>
#include "PaiGowLogic.h"

NS_PAIGOW_BEGIN

class PaiGowResult
{
public:
	PaiGowResult() {};
	virtual  ~PaiGowResult() {};
	void initByPaiGowResult(const proto3_proto::PaiGowResult& result);
public:
	uint32_t seat_id;						//玩家id
	int result;								//分数
	int total_result;					    //总分
	std::vector<Card> cards;
};

NS_PAIGOW_END

#endif