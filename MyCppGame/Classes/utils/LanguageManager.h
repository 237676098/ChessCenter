#ifndef  __LANGUAGE_MANAGER_H__
#define  __LANGUAGE_MANAGER_H__
#include "CommonMacros.h"
#include <string>
#include <map>
#include "cocos2d.h"
NS_CORE_BEGIN

class LanguageManager
{
public:
	bool init();
	const char* get(const std::string& key) const;
private:
	cocos2d::__Dictionary* m_values;
	SINGLETON(LanguageManager)
};


NS_CORE_END

#include "CommonMacros.h"
#endif // ! 
