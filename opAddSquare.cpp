#include "opAddSquare.h"
#include "Square.h"
#include "controller.h"
#include "GUI/GUI.h"

opAddSquare::opAddSquare(controller* pCont) :operation(pCont)
{}
opAddSquare::~opAddSquare()
{}

//Execute the operation
void opAddSquare::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	pUI->PrintMessage("New Square: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all Square parameters
	GfxInfo SquareGfxInfo;

	//get drawing, filling colors and pen width from the interface
	SquareGfxInfo.DrawClr = pUI->getCrntDrawColor();
	SquareGfxInfo.FillClr = pUI->getCrntFillColor();
	SquareGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	SquareGfxInfo.isFilled = pGr->isFilled;	//default is not filled
	SquareGfxInfo.isSelected = false;	//defualt is not selected


	//Create a Circle with the above parameters
	Square* S = new Square(P1, P2, SquareGfxInfo);

	//Add the Squareto the list of shapes
	pGr->Addshape(S);

}


void opAddSquare::Undo()
{
	Graph* pGr = pControl->getGraph();
	pGr->SendFromShapesListToUndo();
}
void opAddSquare::Redo()
{
	Graph* pGr = pControl->getGraph();
	pGr->SendFromUndoToShapesList();
}
