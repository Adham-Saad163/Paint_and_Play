#include "opZoomIn.h"
#include "controller.h"
#include "GUI/GUI.h"

opZoomIn::opZoomIn(controller* pCont) :operation(pCont) {}

opZoomIn::~opZoomIn() {}

void opZoomIn::Execute() {

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	int x, y;

	pUI->ClearStatusBar();
	pUI->CreateDrawToolBar();
	pUI->GetPointClicked(x, y);
	pUI->ClearStatusBar();
	pGr->ZOOMING(1.5, x, y);
}

void opZoomIn::Undo() {}
void opZoomIn::Redo() {}
