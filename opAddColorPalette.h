#pragma once
#include "operations/operation.h"

//Add Color Palette operation class
class opAddColorPalette : public operation
{
public:
	opAddColorPalette(controller* pCont);
	virtual ~opAddColorPalette();

	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};
