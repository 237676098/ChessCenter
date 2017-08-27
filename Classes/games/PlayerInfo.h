#ifndef __PLAYER_INFO_H__
#define __PLAYER_INFO_H__
#include <stdint.h>
#include "core/network/socket/protocol.h"

NS_GAME_BEGIN

class PlayerInfo
{
public:
	PlayerInfo();
	~PlayerInfo();
public:
	void initByPlayerInfo(const proto3_proto::PlayerInfo& info);

public:
	inline void setUID(uint16_t uid) { m_uid = uid; };
	inline void setSeatId(int seatid) { m_seat_id = seatid; };
	inline void setName(std::string name) { m_name = name; };
	inline void setHead(std::string head) { m_head = head; };
	inline void setIP(std::string ip) { m_ip = ip; };
	inline uint64_t getUID() const { return m_uid; };
	inline int getSeatId() const { return m_seat_id; };
	inline std::string getName() const { return m_name; };
	inline std::string getHead() const { return m_head; };
	inline std::string getIP() const { return m_ip; };
 
protected:
	uint64_t m_uid;
	int m_seat_id;
	std::string m_name;
	std::string m_head;
	std::string m_ip;
};


NS_GAME_END

#endif