#ifndef __USER_MANAGER_H__
#define __USER_MANAGER_H__
#include  <string>
#include "utils\CommonMacros.h"
#include "test.pb.h"

NS_USER_BEGIN

class UserManager
{
	SINGLETON(UserManager)
public:
	void initUserInfo(proto3_proto::UserInfo* userInfo);
	bool isInited() const { return m_b_is_inited; };
	inline std::string getId() const { return m_s_id; };
	inline std::string getName() const{ return m_s_name; };
	inline std::string getHead() const { return m_s_head; };
	inline int getCard() const { return m_i_card; };
private:
	std::string m_s_id;
	std::string m_s_name;
	std::string m_s_head;
	int m_i_card;
	bool m_b_is_inited;
};

NS_USER_END
#endif