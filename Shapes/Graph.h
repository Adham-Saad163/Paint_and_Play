#pragma once
#include "Shape.h"
#include <fstream>
#include <vector>
using namespace std;

//forward decl
class GUI;	

struct PickedColor
{
	double Red;
	double Green;
	double Blue;
	// 0R, 0G, 0B is black, which is the default color
};

//A class that is responsible on everything related to shapes
class Graph
{
private:
	vector <shape*> shapesList; //a container to hold all shapes							   
	shape* selectedShape;	//pointer to the currently selected shape
	PickedColor pickedClr;
public:										
	bool isFilled = false;
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)s
	shape* Getshape(int x, int y) const; //Search for a shape given a point inside the shape

	void SaveShapes(ofstream& outfile, GUI* pUI);	//Save all shapes to a file
	void load(ifstream& inputfile, GUI* pUI);	//Load all shapes from a file

	void setFilled(bool);
	void DeleteSelected();
	color ConvertColor(int R, int G, int B);

	void RemoveShape(shape* pShp); // Removes the Last added Shape
	color getColor();
	void setColor(double&, double&, double&); // Sets the color to the chosen color from palette
};
