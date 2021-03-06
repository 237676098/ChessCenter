#include "LoginView.h"
#include "ui/UIButton.h"
#include "core/network/socket/SocketManager.h"
#include "core/scene/scene.h"
#include "AgreementTipsWindow.h"
#include "core/fsm/game_machine.h"
#include "ui/UICheckBox.h"
#include "ui/UITextField.h"
//for http begin
#include "network/HttpClient.h"
#include "json/document.h"  
#include "json/writer.h"  
#include "json/stringbuffer.h"
//for http end
#include "user/user.h"
#include "utils/LanguageManager.h"
#include "games/paigow/views/PaiGowCardView.h"

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

	if (false)
	{
		for (size_t i = 0; i < 21; i++)
		{
			game::paigow::Card card = game::paigow::cards[i];
			//CCLOG("%04X %d",card,card);
		};

		//game::paigow::PaiGowCardView* view = game::paigow::PaiGowCardView::create(0x010c);
		//view->setPosition(g_center);
		//core::SceneManager::getInstance()->add(core::LayerMessage, view);
		return;
	}

	cocos2d::ui::CheckBox* cb_agree = m_csb->getChildByName<cocos2d::ui::CheckBox*>("m_cb_agree");


	if (!cb_agree->isSelected())
	{
		core::WindowManager::getInstance()->open<AgreementTipsWindow>();
		return;
	}
	
	std::string name = m_csb->getChildByName<cocos2d::ui::TextField*>("TextField_1")->getString();
	std::string  postData = "platform=test&source=windows develop&os=windows&ver=v0.1";
	postData.append("&name=" + name).append("&sign=" + name);
	cocos2d::network::HttpRequest* request = new cocos2d::network::HttpRequest();
	request->setUrl("http://47.94.95.187:1009/v1/user/signlogin");
	request->setRequestType(cocos2d::network::HttpRequest::Type::POST);
	request->setResponseCallback(
		[name](cocos2d::network::HttpClient* client, cocos2d::network::HttpResponse* response)->void {
		//pTarget->pSelector(client,response);
		//CCLOG(response->getResponseDataString());
		std::vector<char> *data = response->getResponseData();
		std::string load_str;
		//方法一
		for (size_t i = 0; i < data->size(); ++i) {
			load_str += (*data)[i];
		}
		load_str += '\0';
		//CCLOG(load_str.c_str());

		//*** 读取 json 文件 ***  
		rapidjson::Document readdoc;
		bool bRet = false;
		ssize_t size = 0;

		//load_str = cocos2d::FileUtils::getInstance()->getStringFromFile("..\\myhero.json");  
		readdoc.Parse<0>(load_str.c_str());
		if (readdoc.HasParseError())
		{
			//CCLOG("GetParseError:%d\n", readdoc.GetParseError());
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
				user::UserManager::getInstance()->setSign(name);
				user::UserManager::getInstance()->setId(uid);
				core::SocketManager::getInstance()->Connect(host, port);
			}
		}
	});

	
	request->setRequestData(postData.c_str(), strlen(postData.c_str()));
	cocos2d::network::HttpClient::getInstance()->send(request);
	request->release();

}

NS_LOGIN_END