#include "opAddDrawMode.h"
#include "operations/operation.h"
#include "controller.h"
#include "GUI/GUI.h"


opAddDrawMode::opAddDrawMode(controller* pCont) :operation(pCont)
{
	this->pCont = pCont;
}

//Execute the action
void opAddDrawMode::Execute()
{
	GUI* pUI = pControl->GetUI();

	pUI->ClearToolBar();
	pUI->ClearDrawArea();
	pUI->PrintMessage("Draw Mode");
	pUI->CreateDrawToolBar();
}

void opAddDrawMode::Undo() {}
void opAddDrawMode::Redo() {}