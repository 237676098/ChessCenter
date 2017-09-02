#include "PaiGowSeatView.h"
#include "cocos2d.h"

USING_NS_CC;
NS_PAIGOW_BEGIN

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

void PaiGowSeatView::update()
{
}

void PaiGowSeatView::initView(PaiGowPlayer * player)
{
	m_player = player;
	
	//player name
	m_csb->getChildByName<Text*>("tf_name")->setString(player->name);
	//player score
	m_csb->getChildByName<Text*>("tf_score")->setString(std::to_string(player->score));

	m_csb->getChildByName<Sprite*>("img_is_banker")->setVisible(false);
	m_csb->getChildByName<Sprite*>("img_result")->setVisible(false);
	m_csb->getChildByName<Sprite*>("img_is_ready")->setVisible(false);
	//m_csb->getChildByName<Sprite*>("img_is_banker")->setVisible(false);
}

NS_PAIGOW_END