#include "opDelete.h"
#include"Shapes/Graph.h"

opDelete::opDelete(controller* pCont):operation(pCont)
{
}


void opDelete::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	pUI->PrintMessage("The object is now removed");
	pGraph->DeleteSelected();
}


void opDelete::Undo() 
{
	Graph* pGr = pControl->getGraph();
	pGr->SendFromShapesListToUndo();
}
void opDelete::Redo() 
{
	Graph* pGr = pControl->getGraph();
	pGr->SendFromUndoToShapesList();
}