#pragma once
#include "utils\CommonMacros.h"
#include "ui\UIWidget.h"

using namespace cocos2d::ui;
NS_CORE_BEGIN

class IBaseUI:public Widget
{
public:
	static IBaseUI* create(const std::string fileName = "");
	IBaseUI():m_file_name(""),m_csb(nullptr) {};
	bool init();
	virtual bool initWithFile(const std::string fileName);

protected:
	std::string m_file_name;
	cocos2d::Node* m_csb;
};


NS_CORE_END