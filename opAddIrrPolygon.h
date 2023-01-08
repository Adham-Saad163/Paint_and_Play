#pragma once
#include "operations/operation.h"

//Add irregular polygon operation class
class opAddIrrPolygon : public operation
{
public:
	// creates a pointer "pCont" of class controller
	opAddIrrPolygon(controller* pCont);
	virtual ~opAddIrrPolygon();

	//Add irregular polygon to the controller
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};

