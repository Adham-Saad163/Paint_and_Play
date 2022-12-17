#pragma once
#include "operations/operation.h"
class oppAddTriangle : public operation
{
public:
	oppAddTriangle(controller* pCont);
	virtual ~oppAddTriangle();

	//Add Triangle to the controller
	virtual void Execute();

};

