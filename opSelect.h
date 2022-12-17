#pragma once
#include "operations/operation.h"


class opSelect : public operation
{
private:
	Point P1;
	GfxInfo SelectGfxInfo;
public:
	opSelect(controller* pCont);
	virtual ~opSelect();
	virtual void Execute();
};
