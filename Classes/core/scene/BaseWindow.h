#ifndef __BASE_WINDOW_H__
#define __BASE_WINDOW_H__
#include "utils\CommonMacros.h"
#include "ui\UIWidget.h"
#include "cocos2d.h"

using namespace cocos2d::ui;
NS_CORE_BEGIN
class IBaseWindow :public Widget
{
public:
	IBaseWindow(std::string path, bool is_black = true, bool is_full_screen = false);
	~IBaseWindow();
public:
	void initCSB();
protected:
	virtual void onLoadCompleted();
	virtual void onClickCloseBtn(Ref* btn);
protected:
	std::string m_s_path;
	bool m_b_is_black;
	bool m_b_is_full_screen;
	cocos2d::Node* m_node_csb;
	cocos2d::LayerColor* m_layer_bg;
};

NS_CORE_END

#endif