#include "PaiGowSeatView.h"
#include "cocos2d.h"
#include "utils/LanguageManager.h"

USING_NS_CC;
NS_PAIGOW_BEGIN

const cocos2d::Vec2 PaiGowSeatView::bet_positions[] = {
	Vec2(110,-45),
	Vec2(0,-90),
	Vec2(0,-90),
	Vec2(0,-90),
};

PaiGowSeatView * PaiGowSeatView::create()
{
	PaiGowSeatView* view = new (std::nothrow) PaiGowSeatView();
	if (view && view->init())
	{
		view->autorelease();
		view->initWithFile("paigow/paigow_seat");
		return view;
	}
	CC_SAFE_DELETE(view);
	return nullptr;
}

bool PaiGowSeatView::initWithFile(const std::string fileName)
{
	if (!IBaseUI::initWithFile(fileName))
	{
		return false;
	}
	return true;
}

void PaiGowSeatView::showBanker()
{
	m_csb->getChildByName("img_is_banker")->setVisible(true);
}

void PaiGowSeatView::hideBanker()
{
	m_csb->getChildByName("img_is_banker")->setVisible(false);
}

void PaiGowSeatView::setStatus(const std::string status, bool isHide)
{
	auto txt_status = m_csb->getChildByName<Text*>("txt_status");
	if (isHide)
	{
		txt_status->setVisible(false);
	}
	else
	{
		txt_status->setVisible(true);
		txt_status->setString(core::LanguageManager::getInstance()->get(status));
	}
}


void PaiGowSeatView::showResult(int result)
{
	if (result == -1)
	{
		 
	}
	else if (result == 0)
	{

	}
	else if (result == 1)
	{
		 
	}
}

void PaiGowSeatView::showBet(uint32_t bet1, uint32_t bet2,Vec2 pos)
{
	m_csb->getChildByName("node_bet")->setVisible(true);
	m_csb->getChildByName("node_bet")->setPosition(pos);
	m_csb->getChildByName("node_bet")->getChildByName("node_bet1")->getChildByName<Text*>("txt_bet")->setString(std::to_string(bet1));
	m_csb->getChildByName("node_bet")->getChildByName("node_bet2")->getChildByName<Text*>("txt_bet")->setString(std::to_string(bet2));
}

void PaiGowSeatView::hideBet()
{
	m_csb->getChildByName("node_bet")->setVisible(false);
}

void PaiGowSeatView::showOffline(bool b)
{
	m_csb->getChildByName("node_offline")->setVisible(b);
}

void PaiGowSeatView::setScore(int score)
{
	m_csb->getChildByName<Text*>("tf_score")->setString(std::to_string(score));
}

void PaiGowSeatView::initView(PaiGowPlayer * player)
{
	m_player = player;
	
	//player name
	m_csb->getChildByName<Text*>("tf_name")->setString(player->name);
	//player score
	m_csb->getChildByName<Text*>("tf_score")->setString(std::to_string(player->score));

	//todo  根据player信息来初始化
	reset();
}

void PaiGowSeatView::reset()
{
	m_csb->getChildByName<Sprite*>("img_is_banker")->setVisible(false);
	m_csb->getChildByName<Sprite*>("img_result")->setVisible(false);
	m_csb->getChildByName<Text*>("txt_status")->setVisible(false);
	m_csb->getChildByName("node_offline")->setVisible(false);
	hideBet();
}

NS_PAIGOW_END