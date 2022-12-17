#pragma once
#include "operations/operation.h"

//Add Line operation class
class opAddLine : public operation
{
public:
	opAddLine(controller* pCont);
	virtual ~opAddLine();

	//Add Line to the controller
	virtual void Execute();

};

