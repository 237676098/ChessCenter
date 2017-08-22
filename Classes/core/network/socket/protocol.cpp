#include "protocol.h"

NS_CORE_BEGIN

MESSAGE_GETTER(Ack);
MESSAGE_GETTER(S2C_Error);
MESSAGE_GETTER(C2S_Login);
MESSAGE_GETTER(S2C_InitUserInfo);

MsgGetterMap::value_type init_value[] =
{
	MsgGetterMap::value_type(ID_Ack,GetProtoAck),
	MsgGetterMap::value_type(ID_S2C_Error,GetProtoS2C_Error),
	MsgGetterMap::value_type(ID_C2S_Login,GetProtoC2S_Login),
	MsgGetterMap::value_type(ID_S2C_InitUserInfo,GetProtoS2C_InitUserInfo),
};

NS_CORE_END