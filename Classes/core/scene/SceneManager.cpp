#include"scene.h"
#include "CommonMessageView.h"

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

void SceneManager::add(LayerType layerType, Node* node, int zorder)
{
	m_scene->getChildByTag(layerType)->addChild(node);
	if (zorder != -1)
	{
		node->setLocalZOrder(zorder);
	}
}

void SceneManager::remove(LayerType layerType,Node* node)
{
	m_scene->getChildByTag(layerType)->removeChild(node);
}

void SceneManager::showMsg(const std::string msg)
{
	CommonMessageView* view = CommonMessageView::create(msg);
	add(LayerMessage,view);
	view->fly();
}


NS_CORE_END