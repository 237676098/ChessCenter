#pragma once
#include "utils\CommonMacros.h"
#include "Packet.h"
#include <map>
NS_CORE_BEGIN

//宏定义 根据Packet获取Message
#define MESSAGE_GETTER(_MESSAGE_)			\
proto3_proto::Message* GetProto##_MESSAGE_(char* packet)		\
{																	\
std::string msg_str = std::string(packet);		\
proto3_proto::_MESSAGE_* msg = new proto3_proto::_MESSAGE_();						\
msg->ParseFromString(msg_str);\
return (proto3_proto::Message*)msg;\
}
MESSAGE_GETTER(Ack);

//message id define
const uint32 ID_Ack = 587154137;




//message id maps define
typedef std::function<proto3_proto::Message*(char*)> MsgGetter;
typedef std::map<const uint32, MsgGetter> MsgGetterMap;
MsgGetterMap::value_type init_value[] =
{
	MsgGetterMap::value_type(ID_Ack,GetProtoAck),
};

const static MsgGetterMap message_getter_maps(init_value, init_value + 1);
NS_CORE_END