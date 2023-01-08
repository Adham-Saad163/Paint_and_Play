#include "opAddPlayMode.h"
#include "operations/operation.h"
#include "controller.h"
#include "GUI/GUI.h"


opAddPlayMode::opAddPlayMode(controller* pCont) :operation(pCont)
{
	this->pCont = pCont;
}

//Execute the action
void opAddPlayMode::Execute()
{
	GUI* pUI = pControl->GetUI();

	pUI->ClearToolBar();
	pUI->ClearDrawArea();
	pUI->PrintMessage("Play Mode");
	pUI->CreatePlayToolBar();
}

void opAddPlayMode::Undo() {}
void opAddPlayMode::Redo() {}