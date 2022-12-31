#include "opScrample.h"
#include "controller.h"
#include "GUI/GUI.h"
#include "Shapes/Graph.h"

opScrample::opScrample(controller* pCont) :operation(pCont)
{}

opScrample::~opScrample()
{}

void opScrample::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pGr->Scrample();
	pUI->PrintMessage("Shapes are Scrambled");
	pUI->ClearStatusBar();
}