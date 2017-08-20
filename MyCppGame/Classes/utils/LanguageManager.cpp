#include "LanguageManager.h"
#include"cocos2d/external/tinyxml2/tinyxml2.h"
#include"cocos2d.h"
USING_NS_CC;
NS_CORE_BEGIN

LanguageManager::LanguageManager()
{

}

LanguageManager::~LanguageManager()
{
	
}

bool LanguageManager::init()
{
	auto fileUtils = FileUtils::getInstance();
	auto file = fileUtils->fullPathForFilename("i18n/strings-ch.xml");
	if (!fileUtils->isFileExist(file)) {
		return false;
	}

	Data data = fileUtils->getDataFromFile(file);
	if (data.isNull()) {
		return false;
	}

	tinyxml2::XMLDocument document;
	document.Parse(reinterpret_cast<const char*>(data.getBytes()), data.getSize());

	auto root = document.RootElement();
	if (!root) {
		return false;
	}

	auto node = root->FirstChildElement();
	while (node) {
		std::string name = node->Attribute("name");
		if (!name.empty()) {
			m_values[name] = node->GetText();
		}

		node = node->NextSiblingElement();
	}
	return true;
}

const std::string LanguageManager::get(const std::string& key) const
{
	if (m_values.find(key) != m_values.end())
	{
		return m_values.at(key);
	}else {
		return key;
	}
}

NS_CORE_END
