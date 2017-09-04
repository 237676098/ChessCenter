#include "PaiGowCardView.h"
#include "cocos2d.h"

USING_NS_CC;
NS_PAIGOW_BEGIN

PaiGowCardView * PaiGowCardView::create()
{
	PaiGowCardView* paiGowCardView = new (std::nothrow) PaiGowCardView();
	if (paiGowCardView && paiGowCardView->init())
	{
		paiGowCardView->autorelease();
		paiGowCardView->initWithFile("paigow/paigow_card");
		return paiGowCardView;
	}
	CC_SAFE_DELETE(paiGowCardView);
	return nullptr;
}

bool PaiGowCardView::initWithFile(const std::string fileName)
{
	if (!IBaseUI::initWithFile(fileName))
	{
		return false;
	}

	turnBack(false);
	return true;
}

void PaiGowCardView::setCard(const Card& card)
{
	m_card = card;

	if (card == 0x0000)
	{
		m_csb->getChildByName<Sprite*>("card_num")->setVisible(false);
		return;
	}
	m_csb->getChildByName<Sprite*>("card_num")->setVisible(true);
	std::string filename = std::string("card_").append(std::to_string(card)).append(".png");
	//m_csb.getChildByName<Sprite>("card_num")->getTag();
	m_csb->getChildByName<Sprite*>("card_num")->setSpriteFrame(filename);
}

void PaiGowCardView::turnBack(bool isAnimation)
{
	m_csb->getChildByName<Sprite*>("card_num")->setVisible(false);
}

void PaiGowCardView::turnFront(bool isAnimation)
{
	m_csb->getChildByName<Sprite*>("card_num")->setVisible(true);
}

NS_PAIGOW_END