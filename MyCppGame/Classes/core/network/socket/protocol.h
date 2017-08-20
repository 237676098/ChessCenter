#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

#include <functional>
#include "utils\CommonMacros.h"
#include <map>
#include "test.pb.h"
NS_CORE_BEGIN

typedef unsigned char 		uint8;
typedef unsigned short 		uint16;
typedef unsigned int 		uint32;
typedef unsigned long long 	uint64;
typedef unsigned int MessageId;
typedef std::function<proto3_proto::Message*(char*)> MsgGetter;
typedef std::map<const MessageId, MsgGetter> MsgGetterMap;

//宏定义 根据Packet获取Message
#define MESSAGE_GETTER(_MESSAGE_)			\
proto3_proto::Message* GetProto##_MESSAGE_(char* packet)		\
{																	\
std::string msg_str = std::string(packet);		\
proto3_proto::_MESSAGE_* msg = new proto3_proto::_MESSAGE_();						\
msg->ParseFromString(msg_str);\
return (proto3_proto::Message*)msg;\
}

//message id define uint32
const MessageId ID_Ack = 587154137;


extern MsgGetterMap::value_type init_value[]; 

const static MsgGetterMap message_getter_maps(init_value, init_value + 1);
NS_CORE_END

#endif