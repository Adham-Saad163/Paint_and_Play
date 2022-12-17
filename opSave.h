#pragma once
#include "operations/operation.h"
#include <fstream>
#include <iostream>
#include "controller.h"
#include "GUI/GUI.h"
#include <cstring>
#include <string>

class opSave :
	public operation
{
private:
	ofstream outFile;
	string Name;
	Graph* pGraph;
	GUI* pGUI;

public:
	opSave(controller* pCont);
	virtual void ReadOperationParameters();
	virtual void Execute();
};