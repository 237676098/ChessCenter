#include "PaiGowProxy.h"

NS_PAIGOW_BEGIN

PaiGowProxy::PaiGowProxy(PaiGowSnaptShot* data)
	:m_data(data)
{
	//×¢²áÊÂ¼þ¼àÌý
	MSG_FUNCTION_REGISTER(S2C_PG_StartGame, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_PG_GrabBanker, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_PG_Bet, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_PG_Deal, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_PG_Collocation, PaiGowProxy)
	MSG_FUNCTION_REGISTER(S2C_PG_Result, PaiGowProxy)
}

PaiGowProxy::~PaiGowProxy()
{

}

void PaiGowProxy::onRevS2C_PG_StartGame(google::protobuf::Message* msg)
{

}

void PaiGowProxy::onRevS2C_PG_GrabBanker(google::protobuf::Message* msg)
{

}

void PaiGowProxy::onRevS2C_PG_Bet(google::protobuf::Message* msg)
{

}

void PaiGowProxy::onRevS2C_PG_Deal(google::protobuf::Message* msg)
{

}

void PaiGowProxy::onRevS2C_PG_Collocation(google::protobuf::Message* msg)
{

}

void PaiGowProxy::onRevS2C_PG_Result(google::protobuf::Message* msg)
{

}

NS_PAIGOW_END