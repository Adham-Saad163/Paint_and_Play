#include "UnHide.h"
#include "controller.h"
#include "operations/operation.h"

UnHide::UnHide(controller* pCont) :operation(pCont) {}
UnHide::~UnHide() {}

void UnHide::Execute() {

	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	pGr->UnhideIt(pUI);
}

void UnHide::Undo() {}
void UnHide::Redo() {}