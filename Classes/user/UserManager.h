#ifndef __USER_MANAGER_H__
#define __USER_MANAGER_H__
#include  <string>
#include "core/network/socket/SocketManager.h"

NS_USER_BEGIN

class UserManager
{
	SINGLETON(UserManager)
public:
	void init();
	bool isInited() const { return m_is_inited; };
	inline core::int64 getId() const { return m_id; };
	inline std::string getSign() const { return m_sign; };
	inline std::string getName() const{ return m_name; };
	inline std::string getHead() const { return m_head; };
	inline int getCard() const { return m_card; };
	void setId(const core::int64 id) { m_id = id; };
	void setSign(const std::string sign) { m_sign = sign; };
	void setName(const std::string name) { m_name = name; };
	void setHead(const std::string head) { m_head = head; };
	void setCard(const int card) { m_card = card; };
private:
	void onRevS2C_InitUserInfo(google::protobuf::Message* messgae);
private:
	core::int64 m_id;
	std::string m_sign;
	std::string m_name;
	std::string m_head;
	int m_card;
	bool m_is_inited;
};

NS_USER_END
#endif