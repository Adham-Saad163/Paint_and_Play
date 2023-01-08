
#include "opZoomOut.h"
#include "controller.h"
#include "GUI/GUI.h"

opZoomOut::opZoomOut(controller* pCont) :operation(pCont) {}

opZoomOut::~opZoomOut() {}

void opZoomOut::Execute() {

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	int x, y;

	pUI->ClearStatusBar();
	pUI->CreateDrawToolBar();
	pUI->GetPointClicked(x, y);
	pUI->ClearStatusBar();
	pGr->ZOOMING(0.5, x, y);
}

void opZoomOut::Undo() {}
void opZoomOut::Redo() {}
