#pragma once
#include "operations/operation.h"

class opChangeFill :public operation {
public:

	opChangeFill(controller* pCont);
	virtual ~opChangeFill();

	//Add the operation to the controller
	virtual void Execute();
};