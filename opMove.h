#pragma once
#include "operations/operation.h"

class opMove : public operation
{
public:
	opMove(controller* pCont);
	virtual ~opMove();
	virtual void Execute();

	virtual void Undo() override;
	virtual void Redo() override;
};

