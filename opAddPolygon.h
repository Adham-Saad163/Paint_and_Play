#pragma once

#include "operations/operation.h"

//Add polygon operation class
class opAddPolygon : public operation
{
public:
	// creates a pointer "pCont" of class controller
	opAddPolygon(controller* pCont);
	virtual ~opAddPolygon();

	//Add polygon to the controller
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};

