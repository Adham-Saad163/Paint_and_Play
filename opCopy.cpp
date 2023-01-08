#include "opCopy.h"
#include "opCopy.h"
#include"GUI/GUI.h"
#include"Shapes/Shape.h"
#include"controller.h"
#include <iostream>

opCopy::opCopy(controller* pCont):operation(pCont)
{
}

opCopy::~opCopy(void)
{
}

void opCopy::Execute()
{
	GUI* pGUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();

	
	pGraph->CopyShape();
	pGUI->PrintMessage("Selected shapes have been copied");

	
}

void opCopy::Undo()
{
}

void opCopy::Redo()
{
}
