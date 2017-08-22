#ifndef __HTTP_MANAGER_H__
#define __HTTP_MANAGER_H__
#include "utils\CommonMacros.h"
#include "cocos2d.h"
#include "network/HttpClient.h"
USING_NS_CC;
using namespace network;

NS_CORE_BEGIN
class HttpManager
{
	SINGLETON(HttpManager)
public:
	void send(const char* api, const char* postData, Ref* pTarget, SEL_HttpResponse pSelector);

private:

};
#endif
NS_CORE_END;