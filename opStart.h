#pragma once
#include "operations/operation.h"
class opStart : public operation
{
public:
	opStart(controller* pCont);
	~opStart();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

