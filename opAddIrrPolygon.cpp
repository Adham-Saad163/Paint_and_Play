#include "opAddIrrPolygon.h"
#include "IrrPoly.h"
#include "controller.h"
#include "GUI/GUI.h"


opAddIrrPolygon::opAddIrrPolygon(controller* pCont) :operation(pCont)
{}
opAddIrrPolygon::~opAddIrrPolygon()
{}
//Execute the operation
void opAddIrrPolygon::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	// take number of vertices from the user
	pUI->PrintMessage("New irregular polygon: Enter number of vertices: ");
	int numVertices;
	numVertices = stoi(pUI->GetSrting()); // the stoi() function converts a string to an integer value

	// make sure the entered number of vertices is greater than 2
	while(numVertices < 3)
	{
		pUI->PrintMessage("Error! number of vertices must be 3+");
		numVertices = stoi(pUI->GetSrting());
	}

	
	Point* pi = new Point[numVertices];

	pUI->PrintMessage("Click at point1");
	// taking the "x" and "y" coordinates of vertices 
	for (int i = 0;i < numVertices;i++) {
		pUI->GetPointClicked(pi[i].x, pi[i].y);
		pUI->PrintMessage("Click at point" + to_string(i+2) + ":");
	}
	pUI->ClearStatusBar();

	//Preapre all IrrPolygon parameters
	GfxInfo IrrPolygonGfxInfo;

	//get drawing, filling colors and pen width from the interface
	IrrPolygonGfxInfo.DrawClr = pUI->getCrntDrawColor();
	IrrPolygonGfxInfo.FillClr = pUI->getCrntFillColor();
	IrrPolygonGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	IrrPolygonGfxInfo.isFilled = pGr->isFilled;	//default is not filled
	IrrPolygonGfxInfo.isSelected = false;	//defualt is not selected


	//Create IrrPolygon with above parameters 
	IrrPoly* Irrpol = new IrrPoly(pi, numVertices, IrrPolygonGfxInfo);


	//Add the IrrPolygonto the list of shapes
	pGr->Addshape(Irrpol);

}