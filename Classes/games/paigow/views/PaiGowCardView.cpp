#include "PaiGowCardView.h"
#include "cocos2d.h"

USING_NS_CC;
NS_PAIGOW_BEGIN

PaiGowCardView * PaiGowCardView::create()
{
	PaiGowCardView* paiGowCardView = new (std::nothrow) PaiGowCardView();
	if (paiGowCardView && paiGowCardView->init())
	{
		paiGowCardView->autorelease();
		paiGowCardView->initWithFile("paigow/paigow_card");
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

	listener->onTouchEnded = [this](Touch* touch, Event* event)
	{
		this->onClickCard(this);
	};

	auto sp = m_csb->getChildByName("bg");

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, sp);

	//->getEventDispatcher()->addEventListenerWithFixedPriority(listener,0);
	turnBack(false);
	return true;
}

void PaiGowCardView::setCard(const Card& card)
{
	m_card = card;

	if (card == 0x0000)
	{
		m_csb->getChildByName<Sprite*>("card_num")->setVisible(false);
		return;
	}
	m_csb->getChildByName<Sprite*>("card_num")->setVisible(true);
	std::string filename = std::string("card_").append(std::to_string(card)).append(".png");
	//m_csb.getChildByName<Sprite>("card_num")->getTag();
	m_csb->getChildByName<Sprite*>("card_num")->setSpriteFrame(filename);
}

void PaiGowCardView::turnBack(bool isAnimation)
{
	m_csb->getChildByName<Sprite*>("card_num")->setVisible(false);
}

void PaiGowCardView::turnFront(bool isAnimation)
{
	m_csb->getChildByName<Sprite*>("card_num")->setVisible(true);
}

void PaiGowCardView::onClickCard(Ref * ref)
{
	if (m_callBack)
	{
		m_callBack(this);
	}
}

NS_PAIGOW_END