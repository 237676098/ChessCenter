#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__
#include <stdint.h>
#include <functional>
#include "utils\CommonMacros.h"
#include <map>
#include "core/network/protocol/common.pb.h"
#include "core/network/protocol/game.pb.h"
#include "core/network/protocol/paigow.pb.h"
NS_CORE_BEGIN

typedef std::uint8_t 		uint8;
typedef std::uint16_t 		uint16;
typedef std::uint32_t 		uint32;
typedef std::uint64_t 		uint64;
typedef std::int64_t 		int64;
typedef uint32 MessageId;
typedef std::function<google::protobuf::Message*(char*)> MsgGetter;
typedef std::map<const MessageId, MsgGetter> MsgGetterMap;

//get Packet from Message
#define MESSAGE_GETTER(_MESSAGE_)			\
google::protobuf::Message* GetProto##_MESSAGE_(char* packet)		\
{																	\
std::string msg_str = std::string(packet);		\
proto3_proto::_MESSAGE_* msg = new proto3_proto::_MESSAGE_();						\
msg->ParseFromString(msg_str);\
return (google::protobuf::Message*)msg;\
}

const MessageId ID_Ack = 587154137;
const MessageId ID_S2C_Error = 2101126555;
const MessageId ID_C2S_Login = 4263158788;
const MessageId ID_UserInfo = 1823648250;
const MessageId ID_S2C_InitUserInfo = 2044691574;
const MessageId ID_PlayerInfo = 2156412600;
const MessageId ID_PaiGowConfig = 56903103;
const MessageId ID_PaiGowPlayer = 2857336558;
const MessageId ID_PaiGowResult = 345101612;
const MessageId ID_PaiGowSnapshot = 958345802;
const MessageId ID_S2C_PG_addPlayer = 1200920416;
const MessageId ID_C2S_PG_StartGame = 3567813292;
const MessageId ID_S2C_PG_StartGame = 94932318;
const MessageId ID_C2S_PG_GrabBanker = 3468914758;
const MessageId ID_S2C_PG_GrabBanker = 1311290926;
const MessageId ID_C2S_PG_Bet = 1738246803;
const MessageId ID_S2C_PG_Bet = 3204728445;
const MessageId ID_S2C_PG_Deal = 4186617870;
const MessageId ID_C2S_PG_Collocation = 1821223880;
const MessageId ID_S2C_PG_Collocation = 3869272865;
const MessageId ID_S2C_PG_Result = 2359624198;
const MessageId ID_C2S_PG_Sure = 2671625794;
const MessageId ID_Match = 590988333;
const MessageId ID_C2S_CreateMatch = 2795803258;
const MessageId ID_S2C_CreateMatch = 3744486407;
const MessageId ID_C2S_JoinMatch = 442153932;
const MessageId ID_S2C_MatchSnapshot = 1194346942;


extern MsgGetterMap::value_type init_value[]; 

const static MsgGetterMap message_getter_maps(init_value, init_value + 27);


NS_CORE_END

#endif
