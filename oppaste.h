#pragma once
#include "operations/operation.h"
class oppaste :public operation
{
public:
	oppaste(controller* pcont);
	~oppaste();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

