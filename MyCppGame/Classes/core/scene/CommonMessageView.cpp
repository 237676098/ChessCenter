#include "CommonMessageView.h"
#include "scene.h"
#include"2d\CCActionInterval.h"
USING_NS_CC;
NS_CORE_BEGIN
CommonMessageView * CommonMessageView::create(const std::string msg)
{
	CommonMessageView* msgView = new (std::nothrow) CommonMessageView(msg);
	if (msgView && msgView->init())
	{
		msgView->autorelease();
		msgView->initWithFile("common_msg");
		return msgView;
	}
	CC_SAFE_DELETE(msgView);
	return nullptr;
}

bool CommonMessageView::initWithFile(const std::string fileName)
{
	if (IBaseUI::initWithFile(fileName))
	{
		m_csb->setCascadeOpacityEnabled(true);
		cocos2d::ui::Text* text = dynamic_cast<cocos2d::ui::Text*> (m_csb->getChildByName("m_tf_msg"));
		text->setString(m_msg);

		cocos2d::Size size = text->getContentSize();
		cocos2d::Size imgSize(size.width + 80 > 160? size.width + 80:160,36);
		cocos2d::ui::ImageView* img = dynamic_cast<cocos2d::ui::ImageView*> (m_csb->getChildByName("m_img_bg"));
		img->setContentSize(imgSize); 

		return true;
	}
	return false;
}

void CommonMessageView::fly()
{
	this->setPosition(Point(g_win_size.width / 2, g_win_size.height / 2 - 50));
	MoveTo* move = MoveTo::create(0.5f, Point(g_win_size.width / 2, g_win_size.height - 100));
	EaseSineOut* ease = EaseSineOut::create(move);
	CallFunc* removeC = CallFunc::create([this]() {
		this->removeFromParentAndCleanup(true);
	});
	DelayTime* delay = DelayTime::create(1);
	Sequence* action = Sequence::create(ease, delay, removeC, NULL);
	this->runAction(action);
}

NS_CORE_END