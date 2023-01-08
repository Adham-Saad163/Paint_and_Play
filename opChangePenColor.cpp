
#include "opChangePenColor.h"
#include "Shapes/Shape.h"
#include "controller.h"
#include "GUI/GUI.h"

opChangePenColor::opChangePenColor(controller* pCont) :operation(pCont) {}

opChangePenColor::~opChangePenColor() {}

void opChangePenColor::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	pUI->setDrawColor(pGr->getColor());
	pUI->PrintMessage("Draw Color is Now Changed!");
}


void opChangePenColor::Undo() {}
void opChangePenColor::Redo() {}