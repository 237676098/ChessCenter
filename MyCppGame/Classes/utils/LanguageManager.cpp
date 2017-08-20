#include "LanguageManager.h"
#include"cocos2d/external/tinyxml2/tinyxml2.h"

USING_NS_CC;
NS_CORE_BEGIN

LanguageManager::LanguageManager()
	:m_values(nullptr)
{

}

LanguageManager::~LanguageManager()
{
	CC_SAFE_RELEASE_NULL(m_values);
}

bool LanguageManager::init()
{
	CC_SAFE_RELEASE_NULL(m_values);
	//创建词典类实例，将xml文件加载到词典中
	m_values = __Dictionary::createWithContentsOfFile("i18n/strings-ch.xml");
	m_values->retain();
	return true;
}

const char* LanguageManager::get(const std::string& key) const
{
	return ((__String*)m_values->objectForKey(key))->getCString();
}

NS_CORE_END
