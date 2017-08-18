#pragma once
#include "utils\CommonMacros.h"
#include "BaseUI.h"

//无参open函数
#define WINDOW_OPEN_CONSTRCTOR_DECLARE(__WND__)			\
IBaseWindow* WindowManager::open##__WND__();

#define WINDOW_OPEN_CONSTRCTOR(__WND__)					\
IBaseWindow* WindowManager::open##__WND__()				\
{														\
	__WND__* wnd = new (std::nothrow) __WND__();		\
	if (wnd && wnd->init())								\
	{													\
		wnd->autorelease();								\
		return wnd;										\
	}													\
	CC_SAFE_DELETE(wnd);								\
	return nullptr;										\
}

//带一个参数的open函数
#define WINDOW_OPEN_CONSTRCTOR_DECLARE_1(__WND__,__TYPE1__)				\
IBaseWindow* WindowManager::open##__WND__(__TYPE1__ param1);

#define WINDOW_OPEN_CONSTRCTOR_1(__WND__,__TYPE1__)						\
IBaseWindow* WindowManager::open##__WND__(__TYPE1__ param1)				\
{																		\
	__WND__* wnd = new (std::nothrow) __WND__(param1);					\
	if (wnd && wnd->init())												\
	{																	\
		wnd->autorelease();												\
		return wnd;														\
	}																	\
	CC_SAFE_DELETE(wnd);												\
	return nullptr;														\
}


NS_CORE_BEGIN

class WindowManager
{
	SINGLETON(WindowManager)
public:

	template <typename WIND_NAME>
	void open();

	template <typename WIND_NAME, typename PARAM_TYPE1>
	void open_1(PARAM_TYPE1 param);

	template <typename WIND_NAME, typename PARAM_TYPE1,typename PARAM_TYPE2>
	void open_2(PARAM_TYPE1 param1, PARAM_TYPE2 param2);
private:

};

template <typename WIND_NAME>
void WindowManager::open()
{
	WIND_NAME* wnd = new (std::nothrow) WIND_NAME();
	if (wnd && wnd->init())
	{
		wnd->autorelease();
		wnd->setPosition(cocos2d::Vec2(cocos2d::Director::getInstance()->getWinSize().width / 2, cocos2d::Director::getInstance()->getWinSize().height / 2));
		core::SceneManager::getInstance()->add(core::LayerPopWindow, wnd);
	}
}

template <typename WIND_NAME, typename PARAM_TYPE1>
void WindowManager::open_1(PARAM_TYPE1 param)
{
	WIND_NAME* wnd = new (std::nothrow) WIND_NAME(param);
	if (wnd && wnd->init())
	{
		wnd->autorelease();
		wnd->setPosition(cocos2d::Vec2(cocos2d::Director::getInstance()->getWinSize().width / 2, cocos2d::Director::getInstance()->getWinSize().height / 2));
		core::SceneManager::getInstance()->add(core::LayerPopWindow, wnd);
	}
}

template <typename WIND_NAME, typename PARAM_TYPE1, typename PARAM_TYPE2>
void WindowManager::open_2(PARAM_TYPE1 param1, PARAM_TYPE2 param2)
{
	WIND_NAME* wnd = new (std::nothrow) WIND_NAME(param1, param2);
	if (wnd && wnd->init())
	{
		wnd->autorelease();
		wnd->setPosition(cocos2d::Vec2(cocos2d::Director::getInstance()->getWinSize().width / 2, cocos2d::Director::getInstance()->getWinSize().height / 2));
		core::SceneManager::getInstance()->add(core::LayerPopWindow, wnd);
	}
}

NS_CORE_END
