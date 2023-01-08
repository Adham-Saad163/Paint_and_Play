
#pragma once
#include "operations/operation.h"

class opExit : public operation
{
public:
	opExit(controller* pCont);
	virtual ~opExit();
	virtual void Execute();

	virtual void Undo() override;
	virtual void Redo() override;

};