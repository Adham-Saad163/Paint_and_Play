#pragma once
#include "operations/operation.h"
#include "controller.h"
#include "GUI/GUI.h"
#include <string>

class opCopy:public operation
{

public:
	opCopy(controller* pCont);
	virtual ~opCopy(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

