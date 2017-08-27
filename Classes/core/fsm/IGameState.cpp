#include "IGameState.h"

NS_CORE_BEGIN

GameSnaptshotEvent::~GameSnaptshotEvent()
{
	if (m_snaptshot)
	{
		delete m_snaptshot;
	}
	m_snaptshot = nullptr;
}

void GameSnaptshotEvent::setSnaptShot(proto3_proto::S2C_MatchSnapshot * snaptshot)
{
	if (m_snaptshot)
	{
		delete m_snaptshot;
	}
	m_snaptshot = nullptr;
	m_snaptshot = new proto3_proto::S2C_MatchSnapshot();
	m_snaptshot->CopyFrom(*snaptshot);
}

NS_CORE_END