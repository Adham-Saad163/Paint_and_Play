#include "oppaste.h"
#include "opPaste.h"
#include"GUI/GUI.h"
#include"Shapes/Shape.h"
#include"controller.h"
#include <iostream>
#include"Circle.h"
#include"Line.h"
#include"Square.h"
#include"Shapes/Rect.h"
#include"Triangle.h"
using namespace std;
oppaste::oppaste(controller* pcont) :operation(pcont)
{
}

oppaste::~oppaste()
{
}



void oppaste::Execute()
{
	Point P;
	GUI* pGUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	pGUI->PrintMessage("Click at The Location you want to paste the items at");

	//Read 1 Center and store in point and Radius.
	pGUI->GetPointClicked(P.x, P.y);
	pGraph->PasteShape(P);

	pGUI->ClearStatusBar();

}

void oppaste::Undo()
{
}

void oppaste::Redo()
{
}
