#include "PaiGowCardView.h"
#include "cocos2d.h"

USING_NS_CC;
NS_PAIGOW_BEGIN

PaiGowCardView * PaiGowCardView::create(const Card& card)
{
	PaiGowCardView* paiGowCardView = new (std::nothrow) PaiGowCardView(card);
	if (paiGowCardView && paiGowCardView->init())
	{
		paiGowCardView->autorelease();
		paiGowCardView->initWithFile("paigow/paigow_card");
		paiGowCardView->setCard(card,true);
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
	return true;
}

void PaiGowCardView::setCard(const Card& card, bool isFalse)
{
	if (m_card == card && !isFalse)
	{
		return;
	}

	m_card = card;

	std::string filename = std::string("card_").append(std::to_string(card)).append(".png");
	//m_csb.getChildByName<Sprite>("card_num")->getTag();
	m_csb->getChildByName<Sprite*>("card_num")->setSpriteFrame(filename);
}

NS_PAIGOW_END