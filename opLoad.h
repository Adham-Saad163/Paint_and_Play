#pragma once
#include"GUI/GUI.h"
#include"Shapes/Graph.h"
#include<string>
#include "operations/operation.h"
#include "controller.h"
#include<fstream>

class opLoad: public operation
{
public:
	opLoad(controller* pCont);
	~opLoad();
	void Execute();
};

