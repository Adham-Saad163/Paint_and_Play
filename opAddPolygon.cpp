#include "opAddPolygon.h"
#include "Poly.h"
#include "controller.h"
#include "GUI/GUI.h"


opAddPolygon::opAddPolygon(controller* pCont) :operation(pCont)
{}
opAddPolygon::~opAddPolygon()
{}

//Execute the operation
void opAddPolygon::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();


	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	// take number of vertices from the user
	pUI->PrintMessage("Enter number of vertices: ");
	int numVertices;
	numVertices = stoi(pUI->GetSrting()); // the stoi() function converts a string to an integer value

	while (numVertices < 3)
	{
		pUI->PrintMessage("Error! number of vertices must be 3+");
		numVertices = stoi(pUI->GetSrting());
	}


	//Read 1st point and store in point P1
	Point P1;
	pUI->PrintMessage("New Polygon: Click at first point");
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First point is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg = msg + " ... Click at the center";
	pUI->PrintMessage(msg);

	//Read center point and store in center
	Point center;
	pUI->GetPointClicked(center.x, center.y);
	pUI->ClearStatusBar();


	//Preapre all Polygon parameters
	GfxInfo PolygonGfxInfo;

	//get drawing, filling colors and pen width from the interface
	PolygonGfxInfo.DrawClr = pUI->getCrntDrawColor();
	PolygonGfxInfo.FillClr = pUI->getCrntFillColor();
	PolygonGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	PolygonGfxInfo.isFilled = pGr->isFilled;	//default is not filled
	PolygonGfxInfo.isSelected = false;	//defualt is not selected


	//Create polygon with above parameters 
	Poly* pol = new Poly(P1, center, numVertices,PolygonGfxInfo);

	//Add the Polygonto the list of shapes
	pGr->Addshape(pol);

}


void opAddPolygon::Undo()
{
	Graph* pGr = pControl->getGraph();
	pGr->SendFromShapesListToUndo();
}
void opAddPolygon::Redo()
{
	Graph* pGr = pControl->getGraph();
	pGr->SendFromUndoToShapesList();
}