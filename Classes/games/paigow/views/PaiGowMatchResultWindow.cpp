#include "PaiGowMatchResultWindow.h"
#include "core/fsm/game_machine.h"
#include "games/paigow/PaiGowViewController.h"
#include "utils/LanguageManager.h"
#include <time.h>

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "utils/stdtostring.h"
#endif

NS_PAIGOW_BEGIN

void PaiGowMatchResultWindow::onLoadCompleted()
{
	auto center_node = m_node_csb->getChildByName("center");

	size_t player_num = m_controller->getData()->match_results.size();

	for (size_t i = 0; i < 4; i++)
	{
		auto player_node = center_node->getChildByName("item" + std::to_string(i+ 1));
		if (i < player_num)
		{
			player_node->setVisible(true);
			player_node->getChildByName<Text*>("txt_name")->setString(m_controller->getData()->match_results[i]->name);
			player_node->getChildByName<Text*>("txt_uid")->setString(std::to_string(m_controller->getData()->match_results[i]->uid));
			player_node->getChildByName<Text*>("txt_name")->setString(m_controller->getData()->match_results[i]->name);
			player_node->getChildByName("img_bigwin")->setVisible(m_controller->getData()->match_results[i]->is_big_winner);
		
			auto txt_score = player_node->getChildByName<Text*>("txt_result");
			std::string prefix = "";
			int score = m_controller->getData()->match_results[i]->score;
			if (score > 0)
			{
				prefix = "+";
				player_node->getChildByName<cocos2d::Sprite*>("img_result")->setSpriteFrame("end_img_win.png");
				txt_score->setTextColor(cocos2d::Color4B(255, 141, 0,255));
			}
			else
			{
				txt_score->setTextColor(cocos2d::Color4B(119, 136, 153,255));
				player_node->getChildByName<cocos2d::Sprite*>("img_result")->setSpriteFrame("end_img_lose.png");
			}
			txt_score->setString(prefix.append(std::to_string(score)));

			prefix = core::LanguageManager::getInstance()->get("end_des_max_score");
			player_node->getChildByName<Text*>("txt_max_score")->setString(prefix.append(std::to_string(m_controller->getData()->match_results[i]->max_score)));

			prefix = core::LanguageManager::getInstance()->get("end_des_max_cards");
			std::string max_cards_str = PaiGowLogic::getCardGroupName(m_controller->getData()->match_results[i]->max_cards);
			player_node->getChildByName<Text*>("txt_max_cards")->setString(prefix.append(max_cards_str));

			prefix = core::LanguageManager::getInstance()->get("end_des_max_win_rounds");
			player_node->getChildByName<Text*>("txt_win_nums")->setString(prefix.append(std::to_string(m_controller->getData()->match_results[i]->win_rounds)));

			prefix = core::LanguageManager::getInstance()->get("end_des_max_fail_rounds");
			player_node->getChildByName<Text*>("txt_fail_nums")->setString(prefix.append(std::to_string(m_controller->getData()->match_results[i]->fail_rounds)));
			
			player_node->getChildByName<Text*>("txt_win_all_nums")->setVisible(false);
		}
		else
		{
			player_node->setVisible(false);
		}
	}

	center_node->getChildByName<Button*>("btn_share")->addClickEventListener(std::bind(&PaiGowMatchResultWindow::onClickShare,this,std::placeholders::_1));
	center_node->getChildByName<Button*>("btn_back")->addClickEventListener(std::bind(&PaiGowMatchResultWindow::onClickBack, this, std::placeholders::_1));
	
	std::string roomid = core::LanguageManager::getInstance()->get("room_id") + ":";
	roomid.append(std::to_string(m_controller->getData()->room_id));
	center_node->getChildByName<Text*>("txt_roomid")->setString(roomid);


	time_t t;  //秒时间  
	tm* local; //本地时间   
	char buf[128] = { 0 };

	t = m_controller->getData()->finish_time; //获取目前秒时间  
	local = localtime(&t); //转为本地时间  
	strftime(buf, 64, "%Y-%m-%d %H:%M:%S", local);
	center_node->getChildByName<Text*>("txt_finish_time")->setString(buf);


	
}

void PaiGowMatchResultWindow::onClickBack(Ref * btn)
{
	core::MatchEndEvent event;
	core::GameStateMachine::getInstance()->dispatchEvent(&event);
}

void PaiGowMatchResultWindow::onClickShare(Ref * btn)
{

}


NS_PAIGOW_END
