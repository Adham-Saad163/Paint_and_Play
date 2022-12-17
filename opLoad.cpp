#include "opLoad.h"

opLoad::opLoad(controller* pCont):operation(pCont)
{
}

opLoad::~opLoad()
{
}

void opLoad::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	pUI->PrintMessage("Enter the name of the file you would to load from: ");
	string fileName = pUI->GetSrting();
	ifstream inFile;
	inFile.open(fileName + ".txt");
	pGraph->load(inFile, pUI);

}
