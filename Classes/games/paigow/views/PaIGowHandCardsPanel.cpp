#include "PaiGowHandCardsPanel.h"
#include <math.h>
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

	push(m_cards[index]);
}

void PaiGowHandCardsPanel::pull(uint32_t index)
{
	if (index >= m_cards.size())
	{
		return;
	}
	pull(m_cards[index]);
}

void PaiGowHandCardsPanel::setCards(const std::vector<Card>& cards, bool isShow)
{
	for (size_t i = 0; i < cards.size(); i++)
	{
		if (!m_cards[i])
		{
			m_cards[i] = PaiGowCardView::create();
			this->addChild(m_cards[i]);
			m_cards[i]->setCallBack(std::bind(&PaiGowHandCardsPanel::onClickCard, this, std::placeholders::_1));
		}

		if (isShow && i > 1)
		{
			m_cards[i]->setPosition(PaiGowHandCardsPanel::key_points[i + 2]);
			m_cards[i]->setRotation(-90);
		}
		else
		{
			m_cards[i]->setPosition(PaiGowHandCardsPanel::key_points[i]);
		}


		m_cards[i]->setCard(cards[i]);
	}
}

void PaiGowHandCardsPanel::playCollocation()
{
	m_cards[2]->setPosition(PaiGowHandCardsPanel::key_points[4]);
	m_cards[2]->setRotation(-90);
	m_cards[3]->setPosition(PaiGowHandCardsPanel::key_points[5]);
	m_cards[3]->setRotation(-90);
}

void PaiGowHandCardsPanel::playCollocation(const std::vector<Card>& cards)
{

	std::map<int,int> index_pos;
	std::map<int,bool> indexed;
	std::map<int,bool> indexed1;


	for (size_t i = 0; i < cards.size(); i++)
	{
		for (size_t j = 0; j < m_cards.size(); j++)
		{
			if (cards[i]== m_cards[j]->getCard() && indexed.find(i) == indexed.end() && indexed1.find(j) == indexed1.end())
			{
				indexed.insert(std::make_pair(i,true));
				indexed1.insert(std::make_pair(j, true));
				if (i > 1)
				{
					m_cards[j]->setPosition(PaiGowHandCardsPanel::key_points[i+2]);
					m_cards[j]->setRotation(-90);
				}
				else
				{
					m_cards[j]->setPosition(PaiGowHandCardsPanel::key_points[i]);
					m_cards[j]->setRotation(0);
				}
				break;
			}
		}
	}
}

void PaiGowHandCardsPanel::getResultCards(std::vector<Card>& result1, std::vector<Card>& result2) const
{
	for (size_t i = 0; i < m_cards.size(); i++)
	{
		if (m_cards[i]->getPositionY() > 0)
		{
			result2.push_back(m_cards[i]->getCard());
		}
		else
		{
			result1.push_back(m_cards[i]->getCard());
		}
	}
}


void PaiGowHandCardsPanel::onClickCard(PaiGowCardView * view)
{

	if (!m_interactive)
	{
		return;
	}

	if (view->getPositionY() > 0)
	{
		pull(view);
	}
	else 
	{
		push(view);
	}
}

void PaiGowHandCardsPanel::push(PaiGowCardView * view)
{
	view->setPositionY(25);
}

void PaiGowHandCardsPanel::pull(PaiGowCardView * view)
{
	view->setPositionY(0);
}



NS_PAIGOW_END