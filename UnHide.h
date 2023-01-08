#pragma once
#include "controller.h"

class UnHide :public operation 
{
public:
	UnHide(controller* pCont);
	virtual ~UnHide();
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};