#include "PaiGowResultWindow.h"
#include "games/paigow/PaiGowLogic.h"

NS_PAIGOW_BEGIN

void PaiGowResultWindow::onLoadCompleted()
{
	CCLOG("PaiGowResultWindow onLoadCompleted");
	bool is_win = false;

	for (int i = 0; i < m_result.scores_size(); i++)
	{
		if (m_result.scores(i).seat_id() == m_my_seat)
		{
			if (m_result.scores(i).result() >= 0)
			{
				is_win = true;
			}
			else
			{
				is_win = false;
			}
			break;
		}
	}

	auto center_node = m_node_csb->getChildByName("Node_1"); 
	if (is_win) 
	{
		center_node->getChildByName<cocos2d::Sprite*>("img_bg")->setSpriteFrame("img_win.png");
	}
	else
	{            
		center_node->getChildByName<cocos2d::Sprite*>("img_bg")->setSpriteFrame("img_lose.png"); 
	}

	for (int i = 0; i < 4; i++)
	{
		if (i < m_result.scores_size())
		{
			center_node->getChildByName("item" + std::to_string(i + 1))->setVisible(true);
		}
		else
		{
			center_node->getChildByName("item" + std::to_string(i + 1))->setVisible(false);
		}
	}


}

void PaiGowResultWindow::onClickCloseBtn(Ref * btn)
{
	core::WindowManager::getInstance()->close(PaiGowResultWindow::s_id);
}

NS_PAIGOW_END