#include"SceneManager.h"

USING_NS_CC;
NS_CORE_BEGIN
SINGLETON_C_D(SceneManager)
void SceneManager::initAndRun()
{
	m_scene = Scene::create();
	for (int i = 0; i < LayerCount; i++)
	{
		Layer* layer = Layer::create();
		layer->setTag(i);
		layer->setLocalZOrder(i);
		m_scene->addChild(layer);
	}
	Director::getInstance()->runWithScene(m_scene);
}

void SceneManager::add(LayerType layerType, Node* node)
{
	m_scene->getChildByTag(layerType)->addChild(node);
}

void SceneManager::remove(LayerType layerType,Node* node)
{
	m_scene->getChildByTag(layerType)->addChild(node);
}


NS_CORE_END