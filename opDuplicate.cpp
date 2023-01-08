#include "opDuplicate.h"

#include "controller.h"
#include"Shapes/Shape.h"

#include "GUI/GUI.h"
#include"Shapes/Graph.h"
#include"operations/operation.h"

opDuplicate::opDuplicate(controller* pCont) : operation(pCont)
{}
opDuplicate::~opDuplicate()
{}

//Execute the operation
void opDuplicate::Execute() {
	
	GUI* pGUI = pControl->GetUI();
	
	Graph* pGraph = pControl->getGraph();

	pGraph->duplicateShapes();
	pGUI->PrintMessage("Shapes Duplicated");
	pGUI->ClearStatusBar();

}

void opDuplicate::Undo() {}
void opDuplicate::Redo() {}