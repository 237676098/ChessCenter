#include "PaiGowHandCardsPanel.h"
NS_PAIGOW_BEGIN


const cocos2d::Vec2 PaiGowHandCardsPanel::key_points[6] = {
	cocos2d::Vec2(-100,0),
	cocos2d::Vec2(-35,0),
	cocos2d::Vec2(35,0),
	cocos2d::Vec2(100,0),
	cocos2d::Vec2(72,35),
	cocos2d::Vec2(72,-35),
};

PaiGowHandCardsPanel::PaiGowHandCardsPanel()
{

	for (size_t i = 0; i < 4; i++)
	{
		m_cards.push_back(PaiGowCardView::create());
		this->addChild(m_cards[i]);
		m_cards[i]->setPositionX(PaiGowHandCardsPanel::key_points[i].x);
	}

}

PaiGowHandCardsPanel::~PaiGowHandCardsPanel()
{
	//delete m_cards;
}

void PaiGowHandCardsPanel::push(int index)
{
	if (index >= m_cards.size())
	{
		return;
	}
}

void PaiGowHandCardsPanel::pull(int index)
{
	if (index >= m_cards.size())
	{
		return;
	}
}


NS_PAIGOW_END