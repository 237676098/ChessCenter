#pragma once
#include "utils\CommonMacros.h"
#include "LobbyView.h"

NS_LOBBY_BEGIN
class LobbyManager
{
	SINGLETON(LobbyManager);
public:
	void init();
	void dispose();

private:
	LobbyView* m_view;
};

NS_LOBBY_END