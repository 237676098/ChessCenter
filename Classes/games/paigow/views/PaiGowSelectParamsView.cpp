#include "PaiGowSelectParamsView.h"
#include "cocos2d.h"
#include"games/GameManager.h"
USING_NS_CC;

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "utils/stdtostring.h"
#endif

NS_PAIGOW_BEGIN

void PaiGowSelectParamsView::onLoadCompleted()
{
	cocos2d::Node* c_n = m_node_csb->getChildByName("center_node");
	tabs.clear();
	tab_panels.clear();
	for (size_t i = 0; i < 3; i++)
	{
		auto tab = c_n->getChildByName<ImageView*>("tab" + std::to_string(i));
		auto panel = c_n->getChildByName<ImageView*>("panel" + std::to_string(i));
		tabs.push_back(tab);
		tab_panels.push_back(panel);
	
		auto listener = EventListenerTouchOneByOne::create();
		listener->setSwallowTouches(true);

		listener->onTouchBegan = [](Touch* touch, Event* event)->bool
		{
			// event->getCurrentTarget() 返回 *listener's* sceneGraphPriority 节点.
			auto target = static_cast<Sprite*>(event->getCurrentTarget());

			// 获取当前触控点相对与按钮的位置
			Point locationInNode = target->convertToNodeSpace(touch->getLocation());
			Size s = target->getContentSize();
			Rect rect = Rect(0, 0, s.width, s.height);

			// 检测点击区域
			if (rect.containsPoint(locationInNode))
			{
				log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
				//target->setOpacity(180);
				return true;
			}
			return false;
		};

		listener->onTouchMoved = [](Touch* touch, Event* event)
		{

		};

		listener->onTouchEnded = [this,i](Touch* touch, Event* event)
		{
			this->selectTab(i);
		};
		Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, tab);
	
	}

	for (size_t i = 0; i < 5; i++)
	{
		auto option = tab_panels[0]->getChildByName("option" + std::to_string(i));
		if (option)
		{
			RadioBox* rb = new RadioBox;
			for (size_t i = 0; i < 3; i++)
			{
				CheckBox* cb = option->getChildByName<CheckBox*>("cb" + std::to_string(i + 1));
				if (cb)
				{
					cb->addEventListenerCheckBox(this, checkboxselectedeventselector(PaiGowSelectParamsView::onCbSelected));
					rb->insert(std::make_pair(cb, true));
				}
			}
			rbs0.push_back(rb);
		}
	}
	

	selectTab(0);


	c_n->getChildByName<Button*>("btn_create")->addClickEventListener([this](Ref* ref) {
		if (true)
		{
			game::GameManager::getInstance()->createMatch();
		}
	});
}

void PaiGowSelectParamsView::onClickCloseBtn(Ref * btn)
{
	core::WindowManager::getInstance()->close(PaiGowSelectParamsView::s_id);
}

void PaiGowSelectParamsView::onClickCreate(Ref * btn)
{
}

void PaiGowSelectParamsView::onClickCreateForOthers(Ref * btn)
{
}

void PaiGowSelectParamsView::onClickHasCreated(Ref * btn)
{
}

void PaiGowSelectParamsView::selectTab(int tab)
{
	if (current_tab == tab)
	{
		return;
	}

	current_tab = tab;

	for (size_t i = 0; i < tab_panels.size(); i++)
	{
		if (tab == i)
		{
			tab_panels[i]->setVisible(true);
			tabs[i]->loadTexture("btn_num1.png", TextureResType::PLIST);
			tabs[i]->getChildByName<Text*>("Text_1")->setTextColor(Color4B(255, 203, 0,255));
		}
		else 
		{
			tab_panels[i]->setVisible(false);
			tabs[i]->loadTexture("btn_num2.png", TextureResType::PLIST);
			tabs[i]->getChildByName<Text*>("Text_1")->setTextColor(Color4B(170, 110, 0, 255));
		}
	}
}

void PaiGowSelectParamsView::onCbSelected(Ref * ref, CheckBoxEventType evt_type)
{
	if (evt_type == CHECKBOX_STATE_EVENT_SELECTED)
	{
		for (size_t i = 0; i < rbs0.size(); i++)
		{
			if (rbs0[i]->find(dynamic_cast<CheckBox*>(ref)) !=  rbs0[i]->end())
			{
				RadioBox::iterator iter;
				for (iter = rbs0[i]->begin(); iter != rbs0[i]->end(); iter++)
				{
					if (iter->first == ref)
					{
						iter->first->setEnabled(false);
					}
					else
					{
						iter->first->setSelected(false);
						iter->first->setEnabled(true);
					}
				}

				break;
			}
		}
	}
}

NS_PAIGOW_END
