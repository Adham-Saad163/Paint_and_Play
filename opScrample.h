#pragma once
#include "operations/operation.h"


class opScrample : public operation
{

public:
	opScrample(controller* pCont);
	virtual ~opScrample();
	virtual void Execute();
};

