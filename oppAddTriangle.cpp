#include "oppAddTriangle.h"
#include "Triangle.h"

#include "controller.h"

#include "GUI/GUI.h"
oppAddTriangle::oppAddTriangle(controller* pCont) :operation(pCont)
{}
oppAddTriangle::~oppAddTriangle()
{}
//Execute the operation
void oppAddTriangle::Execute()
{
	Point P1, P2, P3;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	pUI->PrintMessage("New Triangle: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();
	msg += " ... Click at third corner";
	pUI->PrintMessage(msg);
	//Read 3rd corner and store in point P2
	pUI->GetPointClicked(P3.x, P3.y);
	pUI->ClearStatusBar();
	//Preapre all Triangle parameters
	GfxInfo TrianGfxInfo;

	//get drawing, filling colors and pen width from the interface
	TrianGfxInfo.DrawClr = pUI->getCrntDrawColor();
	TrianGfxInfo.FillClr = pUI->getCrntFillColor();
	TrianGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	TrianGfxInfo.isFilled = pGr->isFilled;	//default is not filled
	TrianGfxInfo.isSelected = false;	//defualt is not selected


	//Create a Triangle with the above parameters
	Triangle* T = new Triangle(P1, P2, P3, TrianGfxInfo);

	//Add the Triangle to the list of shapes
	pGr->Addshape(T);

}
