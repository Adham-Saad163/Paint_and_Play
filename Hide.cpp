#include "Hide.h"
#include "controller.h"
#include "operations/operation.h"

Hide::Hide(controller* pCont) :operation(pCont) {}
Hide::~Hide() {}

void Hide::Execute() {

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	pGr->HideIt(pUI);
}

void Hide::Undo() {}
void Hide::Redo() {}
