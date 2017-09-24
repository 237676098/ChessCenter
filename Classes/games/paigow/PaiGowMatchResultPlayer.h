#ifndef __PAI_GOW_MATCH_RESULT_PLAYER_H__
#define __PAI_GOW_MATCH_RESULT_PLAYER_H__
#include <string>
#include "PaiGowLogic.h"

NS_PAIGOW_BEGIN
class PaiGowMatchResultPlayer
{
public:
	std::string name;
	std::string head;
	uint64_t uid;
	Card max_cards[2];
	uint32_t max_score;
	uint32_t win_rounds;
	uint32_t fail_rounds;
	uint32_t win_all_rounds;
	uint32_t fail_all_rounds;
	uint32_t score;
	bool is_big_winner;
};

NS_PAIGOW_END
#endif // !__PAI_GOW_MATCH_RESULT_H__

