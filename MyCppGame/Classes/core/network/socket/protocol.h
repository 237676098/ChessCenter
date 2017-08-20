#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__
#include <stdint.h>
#include <functional>
#include "utils\CommonMacros.h"
#include <map>
#include "test.pb.h"
NS_CORE_BEGIN

typedef std::uint8_t 		uint8;
typedef std::uint16_t 		uint16;
typedef std::uint32_t 		uint32;
typedef std::uint64_t 		uint64;
typedef std::int64_t 		int64;
typedef uint32 MessageId;
typedef std::function<google::protobuf::Message*(char*)> MsgGetter;
typedef std::map<const MessageId, MsgGetter> MsgGetterMap;

//宏定义 根据Packet获取Message
#define MESSAGE_GETTER(_MESSAGE_)			\
google::protobuf::Message* GetProto##_MESSAGE_(char* packet)		\
{																	\
std::string msg_str = std::string(packet);		\
proto3_proto::_MESSAGE_* msg = new proto3_proto::_MESSAGE_();						\
msg->ParseFromString(msg_str);\
return (google::protobuf::Message*)msg;\
}

//message id define uint32
const MessageId ID_Ack = 587154137;
const MessageId ID_S2C_Error = 2101126555;
const MessageId ID_C2S_Login = 4263158788;
const MessageId ID_S2C_InitUserInfo = 2044691574;


extern MsgGetterMap::value_type init_value[]; 

const static MsgGetterMap message_getter_maps(init_value, init_value + 4);
NS_CORE_END

#endif