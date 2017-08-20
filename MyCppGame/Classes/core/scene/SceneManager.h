#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__
#include "utils\CommonMacros.h"
#include "cocos2d.h"

NS_CORE_BEGIN

typedef enum _LayerType
{
	LayerMainUIDown,
	LayerMainUI,
	LayerMainUIUp,
	LayerPopWindow,
	LayerMessage,
	LayerLoading,
	LayerCount
}LayerType;

class SceneManager
{
	SINGLETON(SceneManager)
	
public:
	void initAndRun();
	void add(LayerType layerType, cocos2d::Node* node);
	void remove(LayerType layerType, cocos2d::Node* node);
private:
	cocos2d::Scene* m_scene;
};

NS_CORE_END

#endif