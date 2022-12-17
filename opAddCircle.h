#pragma once

#include "operations/operation.h"

//Add Rectangle operation class
class opAddCircle : public operation
{
public:
	opAddCircle(controller* pCont);
	virtual ~opAddCircle();

	//Add Circle to the controller
	virtual void Execute();

};
