#include "controller.h"
#include "operations\opAddRect.h"
#include "opAddPolygon.h"
#include "opAddIrrPolygon.h"
#include "opAddPlayMode.h"
#include "opAddDrawMode.h"
#include "opAddColorPalette.h"
#include "opChangeFill.h"
#include "oppAddTriangle.h"
#include "opAddLine.h"
#include "opAddCircle.h"
#include "opAddSquare.h"
#include"opSelect.h"
#include "opStick.h"
#include "opDelete.h"
#include "opSave.h"
#include"opLoad.h"
#include"opExit.h"
#include"opRotate.h"
#include"opResize.h"
#include "opMove.h"
#include "opScrample.h"

#include "opChangePenColor.h"
#include "opUndo.h"
#include "opRedo.h"
#include "opZoomIn.h"
#include "opZoomOut.h"
#include"matchShapes.h"

//Constructor
controller::controller()
{
	pGraph = new Graph;
	pGUI = new GUI;	//Create GUI object
}

//==================================================================================//
//								operations-Related Functions							//
//==================================================================================//
operationType controller::GetUseroperation() const
{
	//Ask the input to get the operation from the user.
	return pGUI->GetUseroperation();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an operation and executes it
operation* controller::createOperation(operationType OpType)
{
	operation* pOp = nullptr;
	
	//According to operation Type, create the corresponding operation object
	switch (OpType)
	{

		case DRAW_RECT:
			pOp = new opAddRect(this);
			addNewOp(pOp);
			break;


		case DRAW_CIRC:
			pOp = new opAddCircle(this);
			addNewOp(pOp);
			break;


		case DRAW_LINE:
			pOp = new opAddLine(this);
			addNewOp(pOp);
			break;


		case DRAW_TRI:
			pOp = new oppAddTriangle(this);
			addNewOp(pOp);
			break;


		case DRAW_SQ:
			pOp = new opAddSquare(this);
			addNewOp(pOp);
			break;


		case DRAW_POLY:
			pOp = new opAddPolygon(this);
			addNewOp(pOp);
			break;


		case DRAW_IRRPOLY:
			pOp = new opAddIrrPolygon(this);
			break;


		case DRAW_COLOR_PALETTE:
			pOp = new opAddColorPalette(this);
			break;


		case SELECT:
			pOp = new opSelect(this);
			break;


		case STICK_I:
			pOp = new opStick(this);
			break;


		case TO_PLAY:
			pOp = new opAddPlayMode(this);
			break;


		case TO_DRAW:
			pOp = new opAddDrawMode(this);
			break;


		case CHNG_FILL_CLR:
			pOp = new opChangeFill(this);
			break;

		case CHANGE_PEN_COLOR:
			pOp = new opChangePenColor(this);
			break;

		case ZOOMIN:
			pOp = new opZoomIn(this);
			break;

		case ZOOMOUT:
			pOp = new opZoomOut(this);
			break;

		case DEL:
			pOp = new opDelete(this);
			addNewOp(pOp);
			break;

		case SAVE:
			pOp = new opSave(this);
			break;

		case LOAD:
			pOp = new opLoad(this);
			break;

		case UNDO:
			pOp = new opUndo(this);
			break;

		case REDO:
			pOp = new opRedo(this);
			break;

		case ROTATE:
			pOp = new opRotate(this);
			break;

		case RESIZE:
			pOp = new opResize(this);
			addNewOp(pOp);
			break;

		case MOVE:
			pOp = new opMove(this);
			addNewOp(pOp);

		case SCRAMBLE:
			pOp = new opScrample(this);
			break;

		case EXIT:
			pOp = new opExit(this);			
			break;
		
		case PLAYING_AREA:
			pOp = new matchShapes(this);
			break;

		case STATUS:	//a click on the status bar ==> no operation
			break;

	}

	return pOp;
	
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all shapes on the user interface
void controller::UpdateInterface() const
{	
	pGraph->Draw(pGUI);
}

////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the UI
GUI *controller::GetUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the Graph
Graph* controller::getGraph() const
{
	return pGraph;
}



//Destructor
controller::~controller()
{
	delete pGUI;
	delete pGraph;
	
}



//==================================================================================//
//							Run function											//
//==================================================================================//
void controller::Run()
{
	operationType OpType;
	do
	{
		//1. Ask the GUI to read the required operation from the user
		OpType = GetUseroperation();

		//2. Create an operation coresspondingly
		operation* pOpr = createOperation(OpType);
		 
		//3. Execute the created operation
		if (pOpr)
		{
			pOpr->Execute();//Execute
			//delete pOpr;	//operation is not needed any more ==> delete it
			//pOpr = nullptr;
		}

		//Update the interface
		UpdateInterface();

	} while (OpType != EXIT);

}






//==================================================================================//
//							Undo/Redo Functions										//
//==================================================================================//


// Function to get the last operation added to the stack
operation* controller::getLastDoneOp() {
	if (!Operations.empty()) // if the stack is empty it returns a null pointer 
	{
		return Operations.top();
	}
	else  // otherwise it returns the top of the stack (last action)
	{ 
		return nullptr;
		pGUI->PrintMessage("There are no actions to be undone!");
	}
}

// Function to get the last undone operation added to the stack
operation* controller::getLastUndoneOp()
{
	if (!UndoneOperations.empty())  // if the stack is empty it returns a null pointer 
	{
		return UndoneOperations.top();
	}
	else  // otherwise it returns the top of the stack (last undone action)
	{
		return nullptr;
		pGUI->PrintMessage("There are no actions to be redone!");
	}
}

// Function to add a new operation to the stack
void controller::addNewOp(operation* newOperation)
{
	if (newOperation)
	{
		Operations.emplace(newOperation);
	}
}

// Function to Undo last made action
void controller::Undo()
{
	if (getLastDoneOp())
	{
		UndoneOperations.emplace(getLastDoneOp());
		Operations.pop();
	}

}

// Function to Redo last made action
void controller::Redo()
{
	if (getLastDoneOp())
	{
		Operations.emplace(getLastUndoneOp());
		UndoneOperations.pop();
	}
}