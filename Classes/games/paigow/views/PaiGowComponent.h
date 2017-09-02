#ifndef __PAI_GOW_COMPONENT_H__
#define __PAI_GOW_COMPONENT_H__
#include "core/event/EventManager.h"

NS_PAIGOW_BEGIN

enum class TableState;

class IPaiGowComponent: public core::EventHandler
{
public:
	IPaiGowComponent() {};
	~IPaiGowComponent() {};

	virtual void initView() {};
	virtual int HandleEvent(core::Event *evt) {};

private:

};

NS_CORE_END
#endif // !__PAI_GOW_COMPONENT_H__