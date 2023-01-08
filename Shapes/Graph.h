#pragma once
#include "Shape.h"
#include <fstream>
#include <vector>
#include "../SImage.h"
#include <cstdlib>
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
	vector <shape*> UndoneShapesList; // a container to hold all undone shapes

	vector <shape*> shapesList; //a container to hold all shapes							   
	vector <SImage*> ImagesList;
	shape* selectedShape;	//pointer to the currently selected shape
	PickedColor pickedClr;
	vector <shape*> matchedShapes;
	vector <shape*> selectedShapes;

public:				

	bool isSaved = false;		//boolean to check save & unsave shapes
	void SendFromShapesListToUndo();
	void SendFromUndoToShapesList();

	bool isFilled = false;
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)s
	shape* Getshape(int x, int y) const; //Search for a shape given a point inside the shape
	shape* getSelectedShape();
	void SaveShapes(ofstream& outfile, GUI* pUI);	//Save all shapes to a file
	void load(ifstream& inputfile, GUI* pUI);	//Load all shapes from a file
	void AddImage(SImage* pFig); //Adds a new shape to the shapesList
	void setFilled(bool);
	void DeleteSelected();
	color ConvertColor(int R, int G, int B);
	void Scrample();
	void RemoveShape(shape* pShp); // Removes the Last added Shape
	color getColor();
	void setColor(double&, double&, double&); // Sets the color to the chosen color from palette
	bool isSelected(bool B);
	void ZOOMING(double scale, int x, int y);

	void unSeletAll();
	void addSelectedShape(shape* pNewShape);
	void addMatchedShape(shape *pNewMatchedShape);
	vector <shape*> getMatchedShapes();
	void clearMatchedShapes();
	void DeleteShape(shape* pShpToDelete);
	void HideIt(GUI* pUI);
	void UnhideIt(GUI* pUI);
};
