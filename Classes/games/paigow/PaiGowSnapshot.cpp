#include "PaiGowSnapshot.h"
#include "PaigowManager.h"

NS_PAIGOW_BEGIN

PaiGowSnaptShot::PaiGowSnaptShot()
	:table_state(TableState::Unkown),
	room_owner(0),
	banker_seat_id(0),
	is_match_end(false)
{
	
}

PaiGowSnaptShot::~PaiGowSnaptShot()
{
	clear();
}

void PaiGowSnaptShot::init(const proto3_proto::S2C_MatchSnapshot & mc_st)
{

	for (size_t i = 0; i < 4; i++)
	{
		players.insert(std::make_pair(i + 1, new PaiGowPlayer));
	}

	initByMatch(mc_st.match());
	table_state = (TableState)mc_st.paigow().state();
	room_owner = mc_st.paigow().room_owner();
	banker_seat_id = mc_st.paigow().banker_seat_id();

	size_t server_public_cards_count = mc_st.paigow().public_cards_size();

	for (size_t i = 0; i < server_public_cards_count; i++)
	{
		public_cards.push_back(mc_st.paigow().public_cards(i));
	}

	size_t length = mc_st.paigow().players_size();

	for (size_t i = 0; i < length; i++)
	{
		addPlayer(mc_st.paigow().players(i));
	}


	for (int i = 0; i < mc_st.paigow().results_size(); i++)
	{
		addResult(mc_st.paigow().results(i));
	}
}

void PaiGowSnaptShot::clear()
{
	MatchSnaptShot::clear();
	table_state = TableState::Unkown;
	room_owner = 0;
	banker_seat_id = 0;
	public_cards.clear();
	clearResult();

	std::map<uint32_t, PaiGowPlayer*>::iterator iter;
	for (iter = players.begin(); iter != players.end(); iter++)
	{
		delete iter->second;
	}

	players.clear();
	clearMatchResults();
}

void PaiGowSnaptShot::addPlayer(const proto3_proto::PaiGowPlayer& p)
{
	uint32_t seatid = p.player().seat_id();
	players[seatid]->initByPaiGowPlayer(p);
}

void PaiGowSnaptShot::deletePlayer(uint32_t seatid)
{
	players[seatid]->has_people = false;
}

int PaiGowSnaptShot::getSeatIndex(int seatid) const
{
	int my_seat_id = -1;

	std::map<uint32_t, PaiGowPlayer*>::const_iterator iter;

	for (iter = players.begin(); iter != players.end(); iter++)
	{
		if ((*iter).second->isMainChar())
		{
			my_seat_id = (*iter).second->seat_id - 1;
		}
	}
	seatid--;
	CCASSERT(my_seat_id != -1,"my seat id is null");

	return (seatid + (4 - my_seat_id)) % 4;
}

PaiGowPlayer * PaiGowSnaptShot::getMainPlayer() const
{

	std::map<uint32_t, PaiGowPlayer*>::const_iterator iter;
	for (iter = players.begin();iter != players.end();iter ++)
	{
		if (iter->second->isMainChar())
		{
			return iter->second;
		}
	}
	return nullptr;
}

bool PaiGowSnaptShot::isMainPlayer(uint32_t seat_id) const
{
	std::map<uint32_t, PaiGowPlayer*>::const_iterator iter;
	for (iter = players.begin(); iter != players.end(); iter++)
	{
		if (iter->first == seat_id  && iter->second->isMainChar())
		{
			return true;
		}
	}

	return false;
}

bool PaiGowSnaptShot::isBanker(uint32_t seat_id) const
{
	return banker_seat_id == seat_id;
}

void PaiGowSnaptShot::updatePlayerState(uint32_t seat_id, PlayerStatus status)
{
	CCASSERT(players[seat_id]->has_people, "no people!");
	players[seat_id]->status = status;
}

void PaiGowSnaptShot::updatePlayerState(PlayerStatus status)
{
	std::map<uint32_t, PaiGowPlayer*>::iterator iter;
	for (iter = players.begin(); iter != players.end(); iter++)
	{
		if (iter->second->has_people)
		{
			iter->second->status = status;
		}
	}
}

void PaiGowSnaptShot::clearResult()
{
	std::vector<PaiGowResult*>::iterator iter;

	for (iter = results.begin(); iter != results.end(); iter++)
	{
		delete *iter;
	}

	results.clear();
}

void PaiGowSnaptShot::addResult(const proto3_proto::PaiGowResult & result_s)
{
	PaiGowResult* result = new PaiGowResult;
	result->initByPaiGowResult(result_s);
	results.push_back(result);
}

void PaiGowSnaptShot::clearMatchResults()
{
	for (size_t i = 0; i < match_results.size(); i++)
	{
		delete match_results[i];
		match_results[i] = nullptr;
	}
	match_results.clear();
}

void PaiGowSnaptShot::addMatchResult(const proto3_proto::MatchResultPlayer & match_result)
{
	PaiGowMatchResultPlayer* result = new PaiGowMatchResultPlayer;
	result->name = players[match_result.seat_id()]->name;
	result->uid = players[match_result.seat_id()]->uid;
	result->head = players[match_result.seat_id()]->head;
	result->score = players[match_result.seat_id()]->score;
	result->max_cards[0] = match_result.max_cards(0);
	result->max_cards[1] = match_result.max_cards(1);
	result->max_score = match_result.max_win();
	result->fail_all_rounds = match_result.fail_all_rounds();
	result->win_all_rounds = match_result.win_all_rounds();
	result->fail_rounds = match_result.fail_rounds();
	result->win_rounds = match_result.win_rounds();
	result->fail_all_rounds = match_result.fail_all_rounds();

	//判断是不是分数最高的
	bool is_big_winner = true;
	std::map<uint32_t, PaiGowPlayer*>::const_iterator iter;
	for (iter = players.begin(); iter != players.end(); iter++)
	{
		if (iter ->second->score > result->score)
		{
			is_big_winner = false;
			break;
		}
	}

	result->is_big_winner = is_big_winner;
	match_results.push_back(result);
}

NS_PAIGOW_END