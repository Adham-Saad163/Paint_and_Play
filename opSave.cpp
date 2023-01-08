#include "opSave.h"
#include "controller.h"
#include "GUI/GUI.h"
#include "operations/operation.h"
#include "CMUgraphicsLib/CMUgraphics.h"

opSave::opSave(controller* pCont) :operation(pCont) {}

void opSave::ReadOperationParameters()
{

	pGUI = pControl->GetUI();
	pGUI->PrintMessage("Please, Enter a file name then press enter:  ");
	Name = pGUI->GetSrting() + ".txt";

	outFile.open(Name);
	while (outFile.fail())
	{
		pGUI->PrintMessage("Please write a valid name then press ENTER");
		Name = pGUI->GetSrting();
		outFile.open(Name + ".txt");
		if (outFile.good())
			break;
	}
}
//Execute the action
void  opSave::Execute()
{
	ReadOperationParameters();

	if (outFile.is_open())
	{
		pGraph = pControl->getGraph();
		pGraph->SaveShapes(outFile, pGUI);
		pGUI->PrintMessage("Drawing SAVED");
		outFile.close();
	}
	else {
		pGUI->PrintMessage("Can not open the file!!");
	}
}

void opSave::Undo() {}
void opSave::Redo() {}