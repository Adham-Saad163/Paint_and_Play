#pragma once
#include "operations/operation.h"

class opUndo : public operation
{
public:
	opUndo(controller* pCont);
	virtual ~opUndo();
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};
