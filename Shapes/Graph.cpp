#include "Graph.h"
#include "../GUI/GUI.h"
#include"Rect.h"
#include"../controller.h"
#include"../Shapes/Shape.h"
#include"../Circle.h"
#include"../Line.h"
#include"../Triangle.h"
#include"../Square.h"
#include"../Poly.h"
#include"../IrrPoly.h"


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



color Graph::ConvertColor(int R, int G, int B) {
	color c(R, G, B);
	return c;
}

void Graph::load(ifstream& inputfile, GUI* pUI)
{


	pUI->ClearDrawArea();    //Clear current graph

	if (inputfile.fail())       //Check if the FileName is a valid name
	{
		pUI->PrintMessage("Invalid Name");
		return;
	}
	color DrawClr, FillClr;
	int shape_Count, p_w;

	string g_drawRed, g_drawGreen, g_drawBlue, g_fillRed, g_fillGreen, g_fillBLue;
	//pControl->LoadFig();        //Delete The figure list
	inputfile >> g_drawRed >> g_drawGreen >> g_drawBlue >> g_fillRed >> g_fillGreen >> g_fillBLue;
	int dr = stoi(g_drawRed);
	int dg = stoi(g_drawGreen);
	int db = stoi(g_drawBlue);
	int fr = stoi(g_fillRed);
	int fg = stoi(g_fillGreen);
	int fb = stoi(g_fillBLue);
	DrawClr = ConvertColor(dr, dg, db);
	FillClr = ConvertColor(fr, fg, fb);
	string pen_w;

	inputfile >> pen_w;    //read the Number of Figures


	p_w = stoi(pen_w);
	string numshapes;
	inputfile >> numshapes;
	shape_Count = stoi(numshapes);



	for (int i = 0; i < shape_Count; i++) {
		string name;
		string drawRed, drawGreen, drawBlue, fillRed, fillGreen, fillBLue;
		int ID;
		Point p1, p2, p3;
		string x1, y1, x2, y2, x3, y3;
		GfxInfo Info;
		Info.BorderWdth = 2;

		inputfile >> name;
		if (name == "RECT") {
			inputfile >> ID;
			inputfile >> x1 >> y1 >> x2 >> y2;
			p1.x = stoi(x1);
			p1.y = stoi(y1);
			p2.x = stoi(x2);
			p2.y = stoi(y2);
			inputfile >> drawRed >> drawGreen >> drawBlue;
			int dred = stoi(drawRed);
			int dgreen = stoi(drawGreen);
			int dblue = stoi(drawBlue);
			color DClr = ConvertColor(dred, dgreen, dblue);
			Info.DrawClr = DClr;
			Info.isSelected = false;

			inputfile >> fillRed;
			if (fillRed == "NO_FILL") {
				Info.isFilled = false;
				Info.FillClr = NULL;
			}
			else {

				inputfile >> fillGreen >> fillBLue;
				int fred = stoi(fillRed);
				int fgreen = stoi(fillGreen);
				int fblue = stoi(fillBLue);
				color FClr = ConvertColor(fred, fgreen, fblue);
				Info.FillClr = FClr;
				Info.isFilled = true;
			}

			Rect* R = new Rect(p1, p2, Info);
			Addshape(R);


		}

		else if (name == "Line") {
			inputfile >> ID;
			inputfile >> x1 >> y1 >> x2 >> y2;
			p1.x = stoi(x1);
			p1.y = stoi(y1);
			p2.x = stoi(x2);
			p2.y = stoi(y2);
			inputfile >> drawRed >> drawGreen >> drawBlue;
			int dred = stoi(drawRed);
			int dgreen = stoi(drawGreen);
			int dblue = stoi(drawBlue);
			color DClr = ConvertColor(dred, dgreen, dblue);
			Info.DrawClr = DClr;
			Info.isSelected = false;

			inputfile >> fillRed;
			if (fillRed == "NO_FILL") {
				Info.isFilled = false;
				Info.FillClr = NULL;
			}
			/*else {

				inputfile >> fillGreen >> fillBLue;
				int fred = stoi(fillRed);
				int fgreen = stoi(fillGreen);
				int fblue = stoi(fillBLue);
				color FClr = ConvertColor(fred, fgreen, fblue);
				Info.FillClr = FClr;
				Info.isFilled = true;
			}*/

			Line* L = new Line(p1, p2, Info);
			Addshape(L);


		}
		else if (name == "Triangle") {
			inputfile >> ID;
			inputfile >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
			p1.x = stoi(x1);
			p1.y = stoi(y1);
			p2.x = stoi(x2);
			p2.y = stoi(y2);
			p3.x = stoi(x3);
			p3.y = stoi(y3);
			inputfile >> drawRed >> drawGreen >> drawBlue;
			int dred = stoi(drawRed);
			int dgreen = stoi(drawGreen);
			int dblue = stoi(drawBlue);
			color DClr = ConvertColor(dred, dgreen, dblue);
			Info.DrawClr = DClr;
			Info.isSelected = false;

			inputfile >> fillRed;
			if (fillRed == "NO_FILL") {
				Info.isFilled = false;
				Info.FillClr = NULL;
			}
			else {

				inputfile >> fillGreen >> fillBLue;
				int fred = stoi(fillRed);
				int fgreen = stoi(fillGreen);
				int fblue = stoi(fillBLue);
				color FClr = ConvertColor(fred, fgreen, fblue);
				Info.FillClr = FClr;
				Info.isFilled = true;
			}

			Triangle* T = new Triangle(p1, p2, p3, Info);
			Addshape(T);

		}

		else if (name == "Circle") {

			inputfile >> ID;
			inputfile >> x1 >> y1 >> x2 >> y2;
			p1.x = stoi(x1);
			p1.y = stoi(y1);
			p2.x = stoi(x2);
			p2.y = stoi(y2);
			inputfile >> drawRed >> drawGreen >> drawBlue;
			int dred = stoi(drawRed);
			int dgreen = stoi(drawGreen);
			int dblue = stoi(drawBlue);
			color DClr = ConvertColor(dred, dgreen, dblue);
			Info.DrawClr = DClr;
			Info.isSelected = false;

			inputfile >> fillRed;
			if (fillRed == "NO_FILL") {
				Info.isFilled = false;
				Info.FillClr = NULL;
			}
			else {

				inputfile >> fillGreen >> fillBLue;
				int fred = stoi(fillRed);
				int fgreen = stoi(fillGreen);
				int fblue = stoi(fillBLue);
				color FClr = ConvertColor(fred, fgreen, fblue);
				Info.FillClr = FClr;
				Info.isFilled = true;
			}

			Circle* C = new Circle(p1, p2, Info);
			Addshape(C);

		}
		else if (name == "Poly") {

			inputfile >> ID;
			inputfile >> x1 >> y1 >> x2 >> y2 >> x3;
			int num_Ver = stoi(x3);
			p1.x = stoi(x1);
			p1.y = stoi(y1);
			p2.x = stoi(x2);
			p2.y = stoi(y2);
			inputfile >> drawRed >> drawGreen >> drawBlue;
			int dred = stoi(drawRed);
			int dgreen = stoi(drawGreen);
			int dblue = stoi(drawBlue);
			color DClr = ConvertColor(dred, dgreen, dblue);
			Info.DrawClr = DClr;
			Info.isSelected = false;

			inputfile >> fillRed;
			if (fillRed == "NO_FILL") {
				Info.isFilled = false;
				Info.FillClr = NULL;
			}
			else {

				inputfile >> fillGreen >> fillBLue;
				int fred = stoi(fillRed);
				int fgreen = stoi(fillGreen);
				int fblue = stoi(fillBLue);
				color FClr = ConvertColor(fred, fgreen, fblue);
				Info.FillClr = FClr;
				Info.isFilled = true;
			}

			Poly* P = new Poly(p1, p2, num_Ver, Info);
			Addshape(P);

		}
		else if (name == "Squar") {

			inputfile >> ID;
			inputfile >> x1 >> y1 >> x2 >> y2;

			p1.x = stoi(x1);
			p1.y = stoi(y1);
			p2.x = stoi(x2);
			p2.y = stoi(y2);
			inputfile >> drawRed >> drawGreen >> drawBlue;
			int dred = stoi(drawRed);
			int dgreen = stoi(drawGreen);
			int dblue = stoi(drawBlue);
			color DClr = ConvertColor(dred, dgreen, dblue);
			Info.DrawClr = DClr;
			Info.isSelected = false;

			inputfile >> fillRed;
			if (fillRed == "NO_FILL") {
				Info.isFilled = false;
				Info.FillClr = NULL;
			}
			else {

				inputfile >> fillGreen >> fillBLue;
				int fred = stoi(fillRed);
				int fgreen = stoi(fillGreen);
				int fblue = stoi(fillBLue);
				color FClr = ConvertColor(fred, fgreen, fblue);
				Info.FillClr = FClr;
				Info.isFilled = true;
			}

			Square* S = new Square(p1, p2, Info);
			Addshape(S);

		}


	}
	//UpdateInterface();     //Draw the figure list

	pUI->PrintMessage("Drawing Loaded Successfully");
	pUI->ClearStatusBar();
	pUI->CreateStatusBar();
}