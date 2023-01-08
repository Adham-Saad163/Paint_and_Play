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
	shape* copy = pGraph->GetSelected();
	if (copy) {
		pGraph->setCopied(copy);
		pGUI->PrintMessage("shape is Copied");
		
	}
	else {
		pGUI->PrintMessage("Please Select A shape First");
	}

	
}

void opCopy::Undo()
{
}

void opCopy::Redo()
{
}
