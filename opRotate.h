#pragma once
#include "operations/operation.h"

class opRotate : public operation
{
public:
	opRotate(controller* pCont);
	virtual ~opRotate();


	virtual void Execute();
	virtual void Redo() override;
	virtual void Undo() override;
};