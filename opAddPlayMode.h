#pragma once
#include "operations/operation.h"

class opAddPlayMode : public operation
{
private:
	controller* pCont;
public:
	opAddPlayMode(controller* pCont);
	virtual void Execute();
};




