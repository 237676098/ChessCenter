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
		m_cards.push_back(nullptr);
	}
}

PaiGowHandCardsPanel::~PaiGowHandCardsPanel()
{
	clear();
}

PaiGowHandCardsPanel * PaiGowHandCardsPanel::create()
{
	PaiGowHandCardsPanel* view = new (std::nothrow) PaiGowHandCardsPanel();
	if (view && view->init())
	{
		view->autorelease();
		return view;
	}
	CC_SAFE_DELETE(view);
	return nullptr;
}

void PaiGowHandCardsPanel::clear()
{
	
}

void PaiGowHandCardsPanel::push(uint32_t index)
{
	if (index >= m_cards.size())
	{
		return;
	}
}

void PaiGowHandCardsPanel::pull(uint32_t index)
{
	if (index >= m_cards.size())
	{
		return;
	}
}

void PaiGowHandCardsPanel::setCards(const std::vector<Card>& cards)
{
	if (m_cards.size() == 0)
	{
		for (size_t i = 0; i < 4; i++)
		{
			m_cards.push_back(PaiGowCardView::create());
			this->addChild(m_cards[i]);
			m_cards[i]->setPosition(PaiGowHandCardsPanel::key_points[i]);
		}
	}

	for (size_t i = 0; i < cards.size(); i++)
	{
		m_cards[i]->setCard(cards[i]);
	}
}

void PaiGowHandCardsPanel::playCollocation()
{
	m_cards[2]->setPosition(PaiGowHandCardsPanel::key_points[4]);
	m_cards[3]->setPosition(PaiGowHandCardsPanel::key_points[5]);
}

void PaiGowHandCardsPanel::playCollocation(const std::vector<Card>& cards)
{
	for (size_t i = 0; i < cards.size(); i++)
	{
		for (size_t j = 0; j < m_cards.size(); j++)
		{
			if (cards[i]== m_cards[j]->getCard())
			{
				m_cards[j]->setPosition(PaiGowHandCardsPanel::key_points[i]);
				break;
			}
		}
	}
}


NS_PAIGOW_END