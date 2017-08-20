#ifndef __SCENE_H__
#define __SCENE_H__
#include "utils\CommonMacros.h"
#include "cocos2d.h"
#include "SceneManager.h"
#include "BaseUI.h"
#include "BaseWindow.h"
#include "WindowManager.h"
#include "window_ids.h"

NS_CORE_BEGIN


#define g_win_size (cocos2d::Director::getInstance()->getWinSize())
#define g_visible_size (cocos2d::Director::getInstance()->getVisibleSize())
#define g_origin (cocos2d::Director::getInstance()->getVisibleOrigin())
#define g_center (cocos2d::Vec2(cocos2d::Director::getInstance()->getWinSize().width / 2, cocos2d::Director::getInstance()->getWinSize().height / 2))

NS_CORE_END
#endif