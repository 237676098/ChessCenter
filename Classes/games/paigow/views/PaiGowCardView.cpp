#include "PaiGowCardView.h"
#include "cocos2d.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "utils/stdtostring.h"
#endif

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

	m_sp_bg = m_csb->getChildByName<cocos2d::Sprite*>("bg");
	m_sp_num = m_sp_bg->getChildByName<cocos2d::Sprite*>("card_num");
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, m_sp_bg);

	//->getEventDispatcher()->addEventListenerWithFixedPriority(listener,0);
	turnBack(false);
	return true;
}

void PaiGowCardView::setCard(const Card& card)
{
	m_card = card;

	if (card == 0x0000)
	{
		m_sp_num->setVisible(false);
		return;
	}
	m_sp_num->setVisible(true);
	std::string filename = std::string("card_").append(std::to_string(card)).append(".png");
	m_sp_num->setSpriteFrame(filename);
}

void PaiGowCardView::turnBack(bool isAnimation)
{
	m_sp_num->setVisible(false);
}

void PaiGowCardView::turnFront()
{
	m_sp_num->setVisible(false);

	this->setScaleX(1);

	cocos2d::ScaleTo* scale1 = cocos2d::ScaleTo::create(0.3, 0,1);
	cocos2d::CallFunc* call1 = cocos2d::CallFunc::create([this]() {
		m_sp_num->setVisible(true);
	});
	cocos2d::ScaleTo* scale2 = cocos2d::ScaleTo::create(0.3, 1,1);
	cocos2d::Sequence* seq = cocos2d::Sequence::create(scale1,call1,scale2,NULL);
	m_sp_bg->runAction(seq);
}

void PaiGowCardView::onClickCard(Ref * ref)
{
	if (m_callBack)
	{
		m_callBack(this);
	}
}

NS_PAIGOW_END