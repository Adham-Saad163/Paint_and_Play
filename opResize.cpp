#include "opResize.h"
#include "controller.h"
#include "GUI/GUI.h"

opResize::opResize(controller* pCont) :operation(pCont)
{}
opResize::~opResize()
{}

//Execute the operation
void opResize::Execute()
{
	GUI* pUI = pControl->GetUI();
	Point P1;
	pUI->PrintMessage("Choose a shape to resize ");
	pUI->GetPointClicked(P1.x, P1.y);
	pUI->ClearStatusBar();
	pUI->PrintMessage("Choose The size From(1/4,1/2,2,4) ");
	double size;
	size = stod(pUI->GetSrting());
	pUI->ClearStatusBar();
	Graph* pGr = pControl->getGraph();
	if (pGr->Getshape(P1.x, P1.y) != nullptr)
	{
		shape* Selected_shape = pGr->Getshape(P1.x, P1.y);
		Selected_shape->Resize(size);

	}

}

void opResize::Undo() {
	Graph* pGr = pControl->getGraph();
	pGr->SendFromShapesListToUndo();
}
void opResize::Redo() {
	Graph* pGr = pControl->getGraph();
	pGr->SendFromUndoToShapesList();
}