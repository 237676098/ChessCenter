#include "PaiGowHandCardsPanel.h"
#include <math.h>
#include "cocos2d.h"
NS_PAIGOW_BEGIN


const cocos2d::Vec2 PaiGowHandCardsPanel::key_points[6] = {
	cocos2d::Vec2(-100,0),
	cocos2d::Vec2(-35,0),
	cocos2d::Vec2(35,0),
	cocos2d::Vec2(100,0),
	cocos2d::Vec2(72,35),
	cocos2d::Vec2(72,-35),
};

const float PaiGowHandCardsPanel::key_rotations[6] = {
	0,
	0,
	0,
	0,
	-90,
	-90
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

void PaiGowHandCardsPanel::setCards(const std::vector<Card>& cards)
{
	for (size_t i = 0; i < cards.size(); i++)
	{
		m_cards[i]->setCard(cards[i]);
	}
}

void PaiGowHandCardsPanel::initCards(const std::vector<Card>& cards, bool isShow)
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
			result2.push_back(i);
		}
		else
		{
			result1.push_back(i);
		}
	}
}

void PaiGowHandCardsPanel::playCollocation(const std::vector<Card>& first, const std::vector<Card>& end)
{
	std::map<PaiGowCardView*, size_t> animation_map;
	std::map<PaiGowCardView*, size_t>::const_iterator iter;
	for (size_t j = 0; j  < first.size(); j++)
	{
		for (size_t i = 0; i < m_cards.size(); i++)
		{
			if (i == first[j])
			{
				animation_map.insert(std::make_pair(m_cards[i],j));
				break;
			}
		}
	}

	for (size_t j = 0; j < end.size(); j++)
	{
		for (size_t i = 0; i < m_cards.size(); i++)
		{
			if (i == end[j])
			{
				animation_map.insert(std::make_pair(m_cards[i], j + 4));
				break;
			}
		}
	}

	for (iter = animation_map.begin(); iter != animation_map.end(); iter++)
	{
		cocos2d::MoveTo* move = cocos2d::MoveTo::create(0.5f, key_points[iter->second]);
		cocos2d::RotateTo* rotation = cocos2d::RotateTo::create(0.3f, key_rotations[iter->second]);
		cocos2d::Sequence* seq = cocos2d::Sequence::create(move,rotation, NULL);
		iter->first->runAction(seq);
	}
}

void PaiGowHandCardsPanel::lightCards()
{
	for (size_t i = 0; i < m_cards.size(); i++)
	{
		//先停止动画 复原位置
		m_cards[i]->stopAllActions();
		int key = 0;
		if (i <  2)
		{
			key = i;
		}
		else
		{
			key = i + 2;
		}
		m_cards[i]->setPosition(key_points[key]);
		m_cards[i]->setRotation(key_rotations[key]);

		//播放翻牌动画
		m_cards[i]->turnFront();
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