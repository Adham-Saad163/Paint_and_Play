#pragma once
#include "controller.h"
#include"GUI/GUI.h"
#include"operations/operation.h"

class opDelete: public operation
{
public:
	opDelete(controller* pCont);
	virtual void Execute();

	virtual void Undo() override;
	virtual void Redo() override;
};

