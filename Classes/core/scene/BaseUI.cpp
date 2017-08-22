#include "BaseUI.h"
#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"
NS_CORE_BEGIN

IBaseUI * IBaseUI::create(const std::string fileName)
{
	IBaseUI* baseui = new (std::nothrow) IBaseUI();
	if (baseui && baseui->init())
	{
		baseui->autorelease();
		baseui->initWithFile(fileName);
		return baseui;
	}
	CC_SAFE_DELETE(baseui);
	return nullptr;
}

bool IBaseUI::init()
{
	if (Widget::init())
	{
		return true;
	}

	return false;
}

bool IBaseUI::initWithFile(const std::string fileName)
{
	m_file_name = fileName;
	//widgetFromBinaryFile
	std::string fullPath = "csb/" + fileName  + ".csb";
	m_csb = cocos2d::CSLoader::createNode(fullPath);
	CCASSERT(m_csb, std::string("create base widget from ").append(fullPath.c_str()).append(" failed!").c_str());
	this->setContentSize(m_csb->getContentSize());
	this->addChild(m_csb);
	return true;
}

void IBaseUI::fullScreen()
{
	this->setContentSize(cocos2d::Director::getInstance()->getWinSize());
	m_csb->setContentSize(cocos2d::Director::getInstance()->getWinSize());
	cocos2d::ui::Helper::doLayout(m_csb);
}

NS_CORE_END