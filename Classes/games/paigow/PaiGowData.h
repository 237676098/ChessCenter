#ifndef __PAIGOW_DATA_H__
#define __PAIGOW_DATA_H__
#include "PaiGowLogic.h"
#include "PaiGowSnapshot.h"

NS_PAIGOW_BEGIN

class PaiGowProxy;

class PaiGowData
{
public:
	PaiGowData();
	~PaiGowData();
private:
	friend class PaiGowProxy;
	PaiGowSnaptShot* pg_st;
};


NS_PAIGOW_END

#endif