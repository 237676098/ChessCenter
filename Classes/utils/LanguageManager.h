#ifndef  __LANGUAGE_MANAGER_H__
#define  __LANGUAGE_MANAGER_H__
#include "CommonMacros.h"
#include <string>
#include <map>
NS_CORE_BEGIN

class LanguageManager
{
public:
	bool init();
	const std::string get(const std::string& key) const;
private:
	std::map<std::string,std::string> m_values;
	SINGLETON(LanguageManager)
};


NS_CORE_END

#include "CommonMacros.h"
#endif // ! 
