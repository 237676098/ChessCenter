#include "protocol.h"

NS_CORE_BEGIN

MESSAGE_GETTER(Ack);
MESSAGE_GETTER(S2C_Error);
MESSAGE_GETTER(C2S_Login);
MESSAGE_GETTER(UserInfo);
MESSAGE_GETTER(S2C_InitUserInfo);
MESSAGE_GETTER(PlayerInfo);
MESSAGE_GETTER(PaiGowConfig);
MESSAGE_GETTER(PaiGowPlayer);
MESSAGE_GETTER(PaiGowResult);
MESSAGE_GETTER(PaiGowSnapshot);
MESSAGE_GETTER(S2C_PG_AddPlayer);
MESSAGE_GETTER(C2S_PG_StartGame);
MESSAGE_GETTER(S2C_PG_StartGame);
MESSAGE_GETTER(C2S_PG_GrabBanker);
MESSAGE_GETTER(S2C_PG_GrabBanker);
MESSAGE_GETTER(S2C_PG_GrabBanker_RES);
MESSAGE_GETTER(C2S_PG_Bet);
MESSAGE_GETTER(S2C_PG_Bet);
MESSAGE_GETTER(S2C_PG_Deal);
MESSAGE_GETTER(C2S_PG_Collocation);
MESSAGE_GETTER(S2C_PG_Collocation);
MESSAGE_GETTER(S2C_PG_Result);
MESSAGE_GETTER(C2S_PG_Sure);
MESSAGE_GETTER(S2C_PG_Sure);
MESSAGE_GETTER(Match);
MESSAGE_GETTER(C2S_CreateMatch);
MESSAGE_GETTER(S2C_CreateMatch);
MESSAGE_GETTER(C2S_JoinMatch);
MESSAGE_GETTER(C2S_LeaveMatch);
MESSAGE_GETTER(S2C_LeaveMatch);
MESSAGE_GETTER(S2C_OffLine);
MESSAGE_GETTER(S2C_OnLine);
MESSAGE_GETTER(S2C_MatchSnapshot);


MsgGetterMap::value_type init_value[] =
{
    MsgGetterMap::value_type(ID_Ack,GetProtoAck),
    MsgGetterMap::value_type(ID_S2C_Error,GetProtoS2C_Error),
    MsgGetterMap::value_type(ID_C2S_Login,GetProtoC2S_Login),
    MsgGetterMap::value_type(ID_UserInfo,GetProtoUserInfo),
    MsgGetterMap::value_type(ID_S2C_InitUserInfo,GetProtoS2C_InitUserInfo),
    MsgGetterMap::value_type(ID_PlayerInfo,GetProtoPlayerInfo),
    MsgGetterMap::value_type(ID_PaiGowConfig,GetProtoPaiGowConfig),
    MsgGetterMap::value_type(ID_PaiGowPlayer,GetProtoPaiGowPlayer),
    MsgGetterMap::value_type(ID_PaiGowResult,GetProtoPaiGowResult),
    MsgGetterMap::value_type(ID_PaiGowSnapshot,GetProtoPaiGowSnapshot),
    MsgGetterMap::value_type(ID_S2C_PG_AddPlayer,GetProtoS2C_PG_AddPlayer),
    MsgGetterMap::value_type(ID_C2S_PG_StartGame,GetProtoC2S_PG_StartGame),
    MsgGetterMap::value_type(ID_S2C_PG_StartGame,GetProtoS2C_PG_StartGame),
    MsgGetterMap::value_type(ID_C2S_PG_GrabBanker,GetProtoC2S_PG_GrabBanker),
    MsgGetterMap::value_type(ID_S2C_PG_GrabBanker,GetProtoS2C_PG_GrabBanker),
    MsgGetterMap::value_type(ID_S2C_PG_GrabBanker_RES,GetProtoS2C_PG_GrabBanker_RES),
    MsgGetterMap::value_type(ID_C2S_PG_Bet,GetProtoC2S_PG_Bet),
    MsgGetterMap::value_type(ID_S2C_PG_Bet,GetProtoS2C_PG_Bet),
    MsgGetterMap::value_type(ID_S2C_PG_Deal,GetProtoS2C_PG_Deal),
    MsgGetterMap::value_type(ID_C2S_PG_Collocation,GetProtoC2S_PG_Collocation),
    MsgGetterMap::value_type(ID_S2C_PG_Collocation,GetProtoS2C_PG_Collocation),
    MsgGetterMap::value_type(ID_S2C_PG_Result,GetProtoS2C_PG_Result),
    MsgGetterMap::value_type(ID_C2S_PG_Sure,GetProtoC2S_PG_Sure),
    MsgGetterMap::value_type(ID_S2C_PG_Sure,GetProtoS2C_PG_Sure),
    MsgGetterMap::value_type(ID_Match,GetProtoMatch),
    MsgGetterMap::value_type(ID_C2S_CreateMatch,GetProtoC2S_CreateMatch),
    MsgGetterMap::value_type(ID_S2C_CreateMatch,GetProtoS2C_CreateMatch),
    MsgGetterMap::value_type(ID_C2S_JoinMatch,GetProtoC2S_JoinMatch),
    MsgGetterMap::value_type(ID_C2S_LeaveMatch,GetProtoC2S_LeaveMatch),
    MsgGetterMap::value_type(ID_S2C_LeaveMatch,GetProtoS2C_LeaveMatch),
    MsgGetterMap::value_type(ID_S2C_OffLine,GetProtoS2C_OffLine),
    MsgGetterMap::value_type(ID_S2C_OnLine,GetProtoS2C_OnLine),
    MsgGetterMap::value_type(ID_S2C_MatchSnapshot,GetProtoS2C_MatchSnapshot),

};

NS_CORE_END
