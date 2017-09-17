#include "PaiGowSnapshot.h"
#include "PaigowManager.h"

NS_PAIGOW_BEGIN

PaiGowSnaptShot::PaiGowSnaptShot()
	:table_state(TableState::Unkown),
	room_owner(0),
	banker_seat_id(0)
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

NS_PAIGOW_END