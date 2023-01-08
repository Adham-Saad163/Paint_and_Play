#include "opSelect.h"
#include "controller.h"
#include "GUI/GUI.h"
#include "Shapes/Graph.h"

opSelect::opSelect(controller* pCont) :operation(pCont)
{}

opSelect::~opSelect()
{}

void opSelect::Execute()
{
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("Select a shape!");
	Point P1;

	pUI->GetPointClicked(P1.x, P1.y);
	pUI->ClearStatusBar();
	Graph* pGr = pControl->getGraph();

	if (pGr->Getshape(P1.x, P1.y) != nullptr)
	{
		shape* Selected_shape = pGr->Getshape(P1.x, P1.y);
		Selected_shape->SetSelected(true);
	}
}


void opSelect::Undo() {}
void opSelect::Redo() {}