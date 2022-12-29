
#include "opRotate.h"
#include "controller.h"
#include "GUI/GUI.h"

opRotate::opRotate(controller* pCont) :operation(pCont)
{}
opRotate::~opRotate()
{}

//Execute the operation
void opRotate::Execute()
{
	GUI* pUI = pControl->GetUI();
	Point P1;
	pUI->PrintMessage("select a shape to rotate it 90 degree");
	pUI->GetPointClicked(P1.x, P1.y);
	pUI->ClearStatusBar();
	Graph* pGr = pControl->getGraph();
	if (pGr->Getshape(P1.x, P1.y) != nullptr)
	{
		shape* Selected_shape = pGr->Getshape(P1.x, P1.y);
		Selected_shape->Rotate();

	}

}
