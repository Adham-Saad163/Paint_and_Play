#include "opChangeFill.h"
#include "Shapes/Shape.h"
#include "controller.h"
#include "GUI/GUI.h"

opChangeFill::opChangeFill(controller* pCont) :operation(pCont) {}

opChangeFill::~opChangeFill() {}

void opChangeFill::Execute() 
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	pGr->setFilled(true);
	pUI->setFillcolor(pGr->getColor());
	pUI->PrintMessage("Now shapes will be filled!");
}