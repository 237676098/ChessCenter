#include "PaiGowResultWindow.h"
#include "games/paigow/PaiGowLogic.h"
#include "games/paigow/PaiGowViewController.h"

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
	for (int i = 0; i < 4; i++)
	{
		auto score_node = center_node->getChildByName("item" + std::to_string(i + 1));
		if (i < m_results.size())
		{
			const PaiGowPlayer* player = m_controller->getPlayerBySeatId(m_results[i]->seat_id);
			score_node->setVisible(true);
			score_node->getChildByName<Text*>("txt_name")->setString(player->name);
			score_node->getChildByName < Text* > ("txt_score")->setString(std::to_string(m_results[i]->result));

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
	proto3_proto::C2S_PG_Sure msg;
	core::SocketManager::getInstance()->sendMessage(core::ID_C2S_PG_Sure, msg);
	core::WindowManager::getInstance()->close(PaiGowResultWindow::s_id);
}

void PaiGowResultWindow::onClickSure(Ref * btn) const
{
	
}

NS_PAIGOW_END