#include "opExit.h"
#include"opSave.h"
#include"Shapes/Graph.h"
opExit::opExit(controller* pCont) :operation(pCont)
{}
opExit::~opExit()
{}

void opExit::Execute() {
	string answer;
	GUI* pUI = pControl->GetUI();
	ofstream outFile;
	Graph* pGraph;
	string name;
	pUI->PrintMessage("you want to Exit , If you want to save before that enter yes if not enter no");
	answer = pUI->GetSrting();
	if (answer == "yes")
	{
		pUI = pControl->GetUI();
		pUI->PrintMessage("Please, Enter a file name then press enter:  ");
		name = pUI->GetSrting() + ".txt";

		outFile.open(name);
		while (outFile.fail())
		{
			pUI->PrintMessage("Please write a valid name then press ENTER");
			name = pUI->GetSrting();
			outFile.open(name + ".txt");
			if (outFile.good())
				break;
		}
		if (outFile.is_open())
		{
			pGraph = pControl->getGraph();
			pGraph->SaveShapes(outFile, pUI);
			pUI->PrintMessage("Drawing SAVED");
			outFile.close();
		}
		else {
			pUI->PrintMessage("Can not open the file!!");
		}
	}
	else if (answer == "no")
	{
		exit;
	}
}


void opExit::Undo() {}
void opExit::Redo() {}