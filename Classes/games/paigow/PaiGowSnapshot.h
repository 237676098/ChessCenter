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
	uint32_t table_state;					//����״̬
	uint32_t room_owner; 					//����ӵ����
	Card* public_cards;							//����
	PaiGowPlayer* players;						//�ƾ����
	//repeated PaiGowResult results = 5; 			//���ֵ�ǰ�������
};


NS_PAIGOW_END
#endif // !__PAIGOW_SNAPTSHOT_H__

