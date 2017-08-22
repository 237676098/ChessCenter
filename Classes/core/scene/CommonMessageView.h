#ifndef __COMMON_MESSAGE_H__
#define __COMMON_MESSAGE_H__
#include "BaseUI.h"
NS_CORE_BEGIN
class CommonMessageView:public IBaseUI
{
public:
	static CommonMessageView* create(const std::string msg = "");
	CommonMessageView(const std::string msg = "")
		:m_msg(msg),
		IBaseUI() {};
	bool initWithFile(const std::string fileName);
	void fly();
private:
	std::string m_msg;
};
NS_CORE_END
#endif