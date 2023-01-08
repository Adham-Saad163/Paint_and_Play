#pragma once

#include "DEFS.h"
#include "Shapes\Graph.h"
#include "GUI\GUI.h"
#include"opLoad.h"
#include <stack>

class operation; //forward declaration

//Main class that manages everything in the application.
class controller
{

	stack<operation*> Operations; // Creating a stack called "Operations" to store the made operations
	stack<operation*> UndoneOperations;  // Creating another stack called UndoneOperations to store 

	Graph* pGraph;	//pointe to the grapg
	GUI* pGUI;		//Pointer to UI class
	

public:	
	controller(); 
	~controller();
	
	// -- operation-Related Functions
	//Reads the input command from the user and returns the corresponding operation type
	operationType GetUseroperation() const;
	operation* createOperation(operationType) ; //Creates an operation
	void Run();
	
	Graph* getGraph() const;
	
	// -- Interface Management Functions
	GUI *GetUI() const; //Return pointer to the UI
	void UpdateInterface() const;	//Redraws all the drawing window	


	void Undo(); // Undo function
	void Redo(); // Redo function

	void addNewOp(operation* newOp); // Adds the new made actions to the stack

	operation* getLastDoneOp();  // Returns a pointer to the last added operation to the stack
	operation* getLastUndoneOp();		// Return a pointer to the last undone operation in the stack


};

