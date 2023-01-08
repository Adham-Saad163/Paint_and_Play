#pragma once
#include "operations/operation.h"
#include "controller.h"
#include "GUI/GUI.h"
#include <string>

class opCut :public operation
{

public:
	opCut(controller* pCont);
	virtual ~opCut(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

