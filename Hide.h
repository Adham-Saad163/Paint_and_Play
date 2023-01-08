#pragma once
#include "operations/operation.h"

class Hide :public operation
{
public:
	Hide(controller* pCont);
	virtual ~Hide();
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};
