#include "PaigowBetOperateView.h"
#include "cocos2d.h"
#include "utils/LanguageManager.h"
#include "core/network/socket/SocketManager.h"

USING_NS_CC;
NS_PAIGOW_BEGIN

const uint32_t PaigowBetOperateView::m_chips_level[] = {
	1,2,5,8,10
};

PaigowBetOperateView * PaigowBetOperateView::create()
{
	PaigowBetOperateView* view = new (std::nothrow) PaigowBetOperateView();
	if (view && view->init())
	{
		view->autorelease();
		view->initWithFile("paigow/paigow_bet_operate_view");
		return view;
	}
	CC_SAFE_DELETE(view);
	return nullptr;
}

bool PaigowBetOperateView::initWithFile(const std::string fileName)
{
	if (!IBaseUI::initWithFile(fileName))
	{
		return false;
	}

	for (size_t i = 0; i < 5; i++)
	{
		auto btn = m_csb->getChildByName("node_not_banker")->getChildByName("Node_1")->getChildByName<Button*>("btn" + std::to_string(i + 1));
		btn->setTag(i);
		btn->addClickEventListener(std::bind(&PaigowBetOperateView::onClickChip,this,std::placeholders::_1));
	}

	m_csb->getChildByName("node_not_banker")->getChildByName<Text*>("txt_title")->setString(core::LanguageManager::getInstance()->get("paigow_first_bet"));

	return true;
}

void PaigowBetOperateView::update()
{
}

void PaigowBetOperateView::onClickChip(Ref * ref)
{
	Button* btn = dynamic_cast<Button*>(ref);
	uint32_t chip = m_chips_level[btn->getTag()];

	if (m_chips.size() == 0)
	{
		m_chips.push_back(chip);
		m_csb->getChildByName("node_not_banker")->getChildByName<Text*>("txt_title")->setString(core::LanguageManager::getInstance()->get("paigow_second_bet"));
	}
	else if(m_chips.size() == 1)
	{
		m_chips.push_back(chip);
		setVisible(false);
		proto3_proto::C2S_PG_Bet msg;
		for (size_t i = 0; i < m_chips.size(); i++)
		{
			msg.add_chips(m_chips[i]);
		}
		core::SocketManager::getInstance()->sendMessage(core::ID_C2S_PG_Bet,msg);
	}
}

void PaigowBetOperateView::show(bool is_banker)
{
	if (is_banker)
	{
		m_csb->getChildByName("node_banker")->setVisible(true);
		m_csb->getChildByName("node_not_banker")->setVisible(false);
	}
	else
	{
		m_csb->getChildByName("node_banker")->setVisible(false);
		m_csb->getChildByName("node_not_banker")->setVisible(true);
	}
}


NS_PAIGOW_END