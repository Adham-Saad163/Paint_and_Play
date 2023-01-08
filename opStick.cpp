#include "opStick.h"
#include "opAddSquare.h"
#include "SImage.h"
#include "controller.h"
#include "GUI/GUI.h"

opStick::opStick(controller* pCont) :operation(pCont)
{}
opStick::~opStick()
{}
//Execute the operation
void opStick::Execute()
{
	Point P1;
	int width, height;
	
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage(" Click at point to stick an image to your shape ");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);
	pUI->ClearStatusBar();
	
	Graph* pGr = pControl->getGraph();
	shape* ShapePointer;
	ShapePointer = (pGr->Getshape(P1.x, P1.y));
	GfxInfo SImageGfxInfo;

	if (ShapePointer != NULL)
	{
		SImage* SI = new SImage(P1, 200, 200);
		pGr->AddImage(SI);
		
	
	}
}


void opStick::Undo() {}
void opStick::Redo() {}