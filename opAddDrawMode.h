#pragma once
#include "operations/operation.h"

class opAddDrawMode : public operation
{
private:
	controller* pCont;
public:
	opAddDrawMode(controller* pCont);
	virtual void Execute();
};




