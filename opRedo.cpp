#include "opRedo.h"
#include "GUI/GUI.h"
#include "controller.h"


opRedo::opRedo(controller* pCont) :operation(pCont) {}

opRedo::~opRedo() {};
void opRedo::Undo() {};
void opRedo::Redo() {};


void opRedo::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	if (pControl->getLastUndoneOp())
	{
		pControl->getLastUndoneOp()->Redo();
		pControl->Redo();
		pGr->isSaved = false;
	}
	else {
		pUI->PrintMessage("There is nothing to be Redone!");
	}
};
