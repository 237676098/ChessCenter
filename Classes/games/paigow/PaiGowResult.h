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
	uint32_t seat_id;						//���id
	int result;								//����
	int total_result;					    //�ܷ�
	std::vector<Card> cards;
};

NS_PAIGOW_END

#endif