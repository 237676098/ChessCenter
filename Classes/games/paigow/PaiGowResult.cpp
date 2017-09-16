#include "PaiGowResult.h"

NS_PAIGOW_BEGIN

void PaiGowResult::initByPaiGowResult(const proto3_proto::PaiGowResult & result_s)
{
	seat_id = result_s.seat_id();
	result = result_s.result();
	total_result = result_s.total_result();
	cards.clear();
	for (int i = 0; i < result_s.hand_cards_size(); i++)
	{
		cards.push_back(result_s.hand_cards(i));
	}
}

NS_PAIGOW_END