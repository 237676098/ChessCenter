#include "PaiGowResultWindow.h"
#include "games/paigow/PaiGowLogic.h"
#include "games/paigow/PaiGowViewController.h"
#include "PaiGowHandCardsPanel.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "utils/stdtostring.h"
#endif

NS_PAIGOW_BEGIN

void PaiGowResultWindow::onLoadCompleted()
{
	CCLOG("PaiGowResultWindow onLoadCompleted");
	const PaiGowPlayer* my_player = m_controller->getMyPlayer();

	bool is_win = false;
	/*
	
	uint32 seat_id = 1;                       //玩家id
	int32 result = 2;                       //分数
	int32 total_result =3;                  //总分
	repeated uint32 hand_cards = 4
	
	*/
	auto center_node = m_node_csb->getChildByName("center_node");
	for (size_t i = 0; i < 4; i++)
	{
		auto score_node = center_node->getChildByName("item" + std::to_string(i + 1));
		if (i < m_results.size())
		{
			const PaiGowPlayer* player = m_controller->getPlayerBySeatId(m_results[i]->seat_id);
			score_node->setVisible(true);
			score_node->getChildByName<Text*>("txt_name")->setString(player->name);
			score_node->getChildByName < Text* > ("txt_score")->setString(std::to_string(m_results[i]->result));
			

			PaiGowHandCardsPanel* hand_cards_panel = PaiGowHandCardsPanel::create();
			hand_cards_panel->initCards(m_results[i]->cards, true);
			hand_cards_panel->setScale(0.5);
			hand_cards_panel->setInteractive(false);
			score_node->getChildByName("node_cards")->addChild(hand_cards_panel);

			Card first_cards[2];
			Card second_cards[2];
			first_cards[0] = m_results[i]->cards[0];
			first_cards[1] = m_results[i]->cards[1];
			second_cards[0] = m_results[i]->cards[2];
			second_cards[1] = m_results[i]->cards[3];
			std::string name1 = PaiGowLogic::getCardGroupName(first_cards);
			std::string name2 = PaiGowLogic::getCardGroupName(second_cards);
			score_node->getChildByName < Text* >("txt_card_name")->setString(name1 + " "  + name2);
	
			if (m_controller->isMySeat(m_results[i]->seat_id))
			{
				if (m_results[i]->result > 0)
				{
					is_win = true;
				}
			}
		}
		else
		{
			score_node->setVisible(false);
		}
	}

	
	if (is_win)
	{
		center_node->getChildByName<cocos2d::Sprite*>("img_bg")->setSpriteFrame("img_win.png");
	}
	else
	{
		center_node->getChildByName<cocos2d::Sprite*>("img_bg")->setSpriteFrame("img_lose.png");
	}


}

void PaiGowResultWindow::onClickCloseBtn(Ref * btn)
{
	m_controller->onClickResultViewSure();
	core::WindowManager::getInstance()->close(PaiGowResultWindow::s_id);
}

void PaiGowResultWindow::onClickSure(Ref * btn) const
{
	
}

NS_PAIGOW_END