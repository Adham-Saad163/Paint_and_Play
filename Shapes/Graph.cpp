#include "Graph.h"
#include "../GUI/GUI.h"

Graph::Graph()
{
	selectedShape = nullptr;
}

Graph::~Graph()
{
}

//==================================================================================//
//						shapes Management Functions								//
//==================================================================================//

//Add a shape to the list of shapes
void Graph::Addshape(shape* pShp)
{
	//Add a new shape to the shapes vector
	shapesList.push_back(pShp);	
}
////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
	pUI->ClearDrawArea();
	for (auto shapePointer : shapesList)
		shapePointer->Draw(pUI);
}



bool outSide_shape = true;



shape* Graph::Getshape(int x, int y) const{
	for (auto shapePointer : shapesList) {
		if (shapePointer->insideShape(x, y))
		{
			selectedShape == shapePointer;
			return shapePointer;
			outSide_shape = false;
			break;
		}
		if (outSide_shape)
		{
			shapePointer->SetSelected(0);
			selectedShape == nullptr;
		}
	}
return nullptr;
}

void Graph::setFilled(bool ans)
{
	isFilled = ans;
}


// Remove last printed shape
void Graph::RemoveShape(shape* pShp)
{
	shapesList.pop_back();
}

// Function to get RGB values of the chosen color
color Graph::getColor() 
{
	return color(pickedClr.Red, pickedClr.Green, pickedClr.Blue);
}

// Function to set the chosen color to be the color in action
void Graph::setColor(double& Red, double& Green, double& Blue) 
{
	pickedClr.Red = Red;
	pickedClr.Green = Green;
	pickedClr.Blue = Blue;
}

void Graph::DeleteSelected()
{
	int i = -1;
	for (auto shapePointer : shapesList)
	{
		i++;
		if (shapePointer->IsSelected())
		{
			shapesList.erase(shapesList.begin() + i);
			i--;
		}
	}
}

void Graph::SaveShapes(ofstream& outfile, GUI* pUI) {

	color CrDrwC = pUI->getCrntDrawColor();
	color CrFillC = pUI->getCrntFillColor();
	outfile << (int)CrDrwC.ucRed << " " << (int)CrDrwC.ucGreen << " " << (int)CrDrwC.ucBlue << " ";
	outfile << (int)CrFillC.ucRed << " " << (int)CrFillC.ucGreen << " " << (int)CrFillC.ucBlue << " ";
	outfile << pUI->getCrntPenWidth() << endl;
	int numShapes = shapesList.size();
	outfile << numShapes << endl;

	for (int i = 0; i < shapesList.size(); i++)
	{
		shapesList[i]->Save(outfile, i + 1);

	}
}