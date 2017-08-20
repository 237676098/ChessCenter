#include "protocol.h"

NS_CORE_BEGIN

MESSAGE_GETTER(Ack);

MsgGetterMap::value_type init_value[] =
{
	MsgGetterMap::value_type(ID_Ack,GetProtoAck),
};

NS_CORE_END