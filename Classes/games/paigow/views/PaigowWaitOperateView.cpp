#include "PaigowWaitOperateView.h"
#include "cocos2d.h"
#include "games/paigow/PaigowManager.h"

USING_NS_CC;
NS_PAIGOW_BEGIN

PaiGowWaitOperateView * PaiGowWaitOperateView::create()
{
	PaiGowWaitOperateView* view = new (std::nothrow) PaiGowWaitOperateView();
	if (view && view->init())
	{
		view->autorelease();
		view->initWithFile("paigow/paigow_wait_operate_view");
		return view;
	}
	CC_SAFE_DELETE(view);
	return nullptr;
}

bool PaiGowWaitOperateView::initWithFile(const std::string fileName)
{
	if (!IBaseUI::initWithFile(fileName))
	{
		return false;
	}

	m_csb->getChildByName<Button*>("m_btn_start")->addClickEventListener([this](Ref*) {
		proto3_proto::C2S_PG_StartGame msg;
		core::SocketManager::getInstance()->sendMessage(core::ID_C2S_PG_StartGame, msg);
	});

	m_csb->getChildByName<Button*>("m_btn_quit")->addClickEventListener([this](Ref*) {
		proto3_proto::C2S_LeaveMatch msg;
		core::SocketManager::getInstance()->sendMessage(core::ID_C2S_LeaveMatch, msg);
	});

	m_csb->getChildByName<Button*>("m_btn_invite")->addClickEventListener([this](Ref*) {

	});

	return true;
}

void PaiGowWaitOperateView::initView(PaiGowSnaptShot * data)
{
	m_data = data;
	PaiGowPlayer* mainPlayer = m_data->getMainPlayer();
	if (mainPlayer->uid == m_data->room_owner)
	{
		m_csb->getChildByName("m_btn_start")->setVisible(true);
	}
	else 
	{
		m_csb->getChildByName("m_btn_start")->setVisible(false);
	}

	bool isFull = true;
	for (size_t i = 0; i < 4; i++)
	{
		if (!m_data->players[i])
		{
			isFull = false;
			break;
		}
	}

	if (isFull)
	{
		m_csb->getChildByName("m_btn_invite")->setVisible(false);
	}
	else
	{
		m_csb->getChildByName("m_btn_invite")->setVisible(true);
	}
}


NS_PAIGOW_END