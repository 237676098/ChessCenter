#ifndef __PAIGOW_PROXY_H__
#define __PAIGOW_PROXY_H__
#include "PaigowManager.h"
#include "core/network/socket/SocketManager.h"

NS_PAIGOW_BEGIN

class PaiGowProxy
{
public:
	PaiGowProxy(PaiGowSnaptShot* data);
	~PaiGowProxy();

private:
	MSG_FUNCTION_DEFINE(S2C_PG_StartGame)
	MSG_FUNCTION_DEFINE(S2C_PG_GrabBanker)
	MSG_FUNCTION_DEFINE(S2C_PG_Bet)
	MSG_FUNCTION_DEFINE(S2C_PG_Deal)
	MSG_FUNCTION_DEFINE(S2C_PG_Collocation)
	MSG_FUNCTION_DEFINE(S2C_PG_Result)
	MSG_FUNCTION_DEFINE(S2C_PG_AddPlayer)
	MSG_FUNCTION_DEFINE(S2C_LeaveMatch)
	MSG_FUNCTION_DEFINE(S2C_OffLine)
	MSG_FUNCTION_DEFINE(S2C_OnLine)

private:
	PaiGowSnaptShot* m_data;
};


NS_PAIGOW_END

#endif