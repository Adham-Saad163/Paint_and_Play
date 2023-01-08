#include "opStick.h"
#include "controller.h"
#include "GUI/GUI.h"

opStick::opStick(controller* pCont) :operation(pCont)
{}
opStick::~opStick()
{}
//Execute the operation
void opStick::Execute()
{
	
	
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	Graph* pGr = pControl->getGraph();
	
	
	if (pGr->getSelectedShape())
	{
		
		pGr->getSelectedShape()->IsSticked = true;
	
	}
}


void opStick::Undo() {}
void opStick::Redo() {}