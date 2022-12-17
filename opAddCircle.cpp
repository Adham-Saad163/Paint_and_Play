#include "opAddCircle.h"

#include "Circle.h"

#include "controller.h"

#include "GUI/GUI.h"

opAddCircle::opAddCircle(controller* pCont) :operation(pCont)
{}
opAddCircle::~opAddCircle()
{}
//Execute the operation
void opAddCircle::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	pUI->PrintMessage("New Circle: Choose The Center");
	//Read first Point and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "the Radiu is at(" + to_string(P1.x) + ", " + to_string(P1.y) + ")";
	msg += " ... Click at second Point to Choose the radius";
	pUI->PrintMessage(msg);
	//Read 2nd point and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all Circle parameters
	GfxInfo RectGfxInfo;

	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pUI->getCrntDrawColor();
	RectGfxInfo.FillClr = pUI->getCrntFillColor();
	RectGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	RectGfxInfo.isFilled = pGr->isFilled;	//default is not filled
	RectGfxInfo.isSelected = false;	//defualt is not selected


	//Create a Circle with the above parameters
	Circle* C = new Circle(P1, P2, RectGfxInfo);


	//Add the circle to the list of shapes
	pGr->Addshape(C);

}
