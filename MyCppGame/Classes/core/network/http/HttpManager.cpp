#include "HttpManager.h"
NS_CORE_BEGIN

void HttpManager::send(const char* api,const char* postData, Ref* pTarget, SEL_HttpResponse pSelector)
{
	HttpRequest* request = new HttpRequest();
	request->setUrl("postÇëÇóÍøÖ·");
	request->setRequestType(HttpRequest::Type::POST);
	pTarget->retain();
	request->setResponseCallback(
	[pTarget](HttpClient* client, HttpResponse* response)->void {
		//pTarget->pSelector(client,response);
		pTarget->release();
	});
	request->setRequestData(postData, strlen(postData));
	HttpClient::getInstance()->send(request);
	request->release();
}

NS_CORE_END
