#pragma once
#include "operations/operation.h"

class opChangePenColor :public operation {
public:

	opChangePenColor(controller* pCont);
	virtual ~opChangePenColor();

	//Add the operation to the controller
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};