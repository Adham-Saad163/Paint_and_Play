#include "opCut.h"

opCut::opCut(controller* pCont):operation(pCont)
{
}

opCut::~opCut(void)
{
}

void opCut::Execute()
{

	GUI* pGUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();

	
	pGraph->CutShape();
	pGUI->PrintMessage("Selected shapes have been cut");
}

void opCut::Undo()
{
}

void opCut::Redo()
{
}
