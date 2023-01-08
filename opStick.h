#pragma once
#include "operations/operation.h"


class opStick : public operation
{
public:
	opStick(controller* pCont);
	virtual ~opStick();
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};
