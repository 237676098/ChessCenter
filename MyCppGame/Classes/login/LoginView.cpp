#include "LoginView.h"
#include "ui\UIButton.h"
#include "socket\SocketManager.h"
#include "core\scene\scene.h"
#include "AgreementTipsWindow.h"
#include "core\fsm\game_machine.h"
//for http begin
#include "network/HttpClient.h"
#include "json/document.h"  
#include "json/writer.h"  
#include "json/stringbuffer.h"
//for http end
#include "user\user.h"
#include "utils/LanguageManager.h"

using namespace  rapidjson;
using namespace cocos2d::ui;
NS_LOGIN_BEGIN

LoginView * LoginView::create()
{
	LoginView* loginView = new (std::nothrow) LoginView();
	if (loginView && loginView->init())
	{
		loginView->autorelease();
		loginView->initWithFile("login");
		return loginView;
	}
	CC_SAFE_DELETE(loginView);
	return nullptr;
}


bool LoginView::initWithFile(const std::string fileName)
{
	if (!IBaseUI::initWithFile(fileName))
	{
		return false;
	}

	Button* loginBtn= dynamic_cast<Button*>(m_csb->getChildByName("center")->getChildByName("Button_1"));
	loginBtn->addClickEventListener(std::bind(&LoginView::onLoginBtnClick,this,std::placeholders::_1));
	loginBtn->setPressedActionEnabled(true);
	loginBtn->setZoomScale(0.04f);
	return true;
}

void LoginView::onLoginBtnClick(Ref* btn)
{
	//core::SocketManager::getInstance()->Send(nullptr);
	//core::WindowManager::getInstance()->open_2<AgreementTipsWindow,std::string,int>("1231",1);
	//core::UserInfoInitedEvent event;
	//core::GameStateMachine::getInstance()->dispatchEvent(event);
	//core::SocketManager::getInstance()->Connect("47.94.95.187", 1008);

	if (true)
	{
		core::SceneManager::getInstance()->showMsg(core::LanguageManager::getInstance()->get("app_name"));
		return;
	}

	cocos2d::network::HttpRequest* request = new cocos2d::network::HttpRequest();
	request->setUrl("http://47.94.95.187:1009/v1/user/signlogin");
	request->setRequestType(cocos2d::network::HttpRequest::Type::POST);
	request->setResponseCallback(
		[](cocos2d::network::HttpClient* client, cocos2d::network::HttpResponse* response)->void {
		//pTarget->pSelector(client,response);
		//CCLOG(response->getResponseDataString());
		std::vector<char> *data = response->getResponseData();
		std::string load_str;
		//方法一
		for (size_t i = 0; i < data->size(); ++i) {
			load_str += (*data)[i];
		}
		load_str += '\0';
		CCLOG(load_str.c_str());

		//*** 读取 json 文件 ***  
		rapidjson::Document readdoc;
		bool bRet = false;
		ssize_t size = 0;

		//load_str = cocos2d::FileUtils::getInstance()->getStringFromFile("..\\myhero.json");  
		readdoc.Parse<0>(load_str.c_str());
		if (readdoc.HasParseError())
		{
			CCLOG("GetParseError%s\n", readdoc.GetParseError());
		}

		if (!readdoc.IsObject())
			return;
		rapidjson::Value& _code = readdoc["code"];
		int code = _code.GetInt();
		if (code == 0)
		{
			rapidjson::Value& _data = readdoc["data"];
			if (_data.IsObject())
			{
				rapidjson::Value& _uid = _data["uid"];
				core::int64 uid = _uid.GetInt64();
				
				rapidjson::Value& _host = _data["host"];
				std::string host = _host.GetString();

				rapidjson::Value& _port = _data["port"];
				core::uint16 port = _port.GetUint();
				user::UserManager::getInstance()->setSign("weinxindesign");
				user::UserManager::getInstance()->setId(uid);
				core::SocketManager::getInstance()->Connect(host, port);
			}
		}
	});
	const char* postData = "sign=weinxindesign&platform=test&name=zhouxu&source=windows develop&os=windows&ver=v0.1";
	request->setRequestData(postData, strlen(postData));
	cocos2d::network::HttpClient::getInstance()->send(request);
	request->release();

}

NS_LOGIN_END