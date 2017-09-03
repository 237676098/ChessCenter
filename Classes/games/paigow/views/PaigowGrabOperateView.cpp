#include "PaigowGrabOperateView.h"
#include "cocos2d.h"
#include "core/network/socket/SocketManager.h"

USING_NS_CC;
NS_PAIGOW_BEGIN

PaigowGrabOperateView * PaigowGrabOperateView::create()
{
	PaigowGrabOperateView* view = new (std::nothrow) PaigowGrabOperateView();
	if (view && view->init())
	{
		view->autorelease();
		view->initWithFile("paigow/paigow_grab_operate_view");
		return view;
	}
	CC_SAFE_DELETE(view);
	return nullptr;
}

bool PaigowGrabOperateView::initWithFile(const std::string fileName)
{
	if (!IBaseUI::initWithFile(fileName))
	{
		return false;
	}

	m_csb->getChildByName<Button*>("btn_grab")->addClickEventListener(
		[this](Ref* ref) {
			this->setVisible(false);
			proto3_proto::C2S_PG_GrabBanker msg;
			msg.set_is_grab(true);
			core::SocketManager::getInstance()->sendMessage(core::ID_C2S_PG_GrabBanker,msg);
		}
	);

	m_csb->getChildByName<Button*>("btn_grab")->addClickEventListener(
		[this](Ref* ref) {
			this->setVisible(false);
			proto3_proto::C2S_PG_GrabBanker msg;
			msg.set_is_grab(false);
			core::SocketManager::getInstance()->sendMessage(core::ID_C2S_PG_GrabBanker, msg);
		}
	);

	return true;
}


NS_PAIGOW_END