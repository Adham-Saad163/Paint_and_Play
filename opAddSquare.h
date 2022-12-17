#pragma once

#include "operations/operation.h"

//Add Square operation class
class opAddSquare : public operation
{
public:
	opAddSquare(controller* pCont);
	virtual ~opAddSquare();

	//Add Square to the controller
	virtual void Execute();

};

