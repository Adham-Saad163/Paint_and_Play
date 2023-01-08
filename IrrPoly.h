#pragma once
#include "Shapes/Shape.h"

class IrrPoly : public shape
{
private:
	int numVertices = 0;
	Point* Arr ;
	string Image = "images\\MenuIcons\\Menu_Stick_Image.jpg";
	// making two dynamic arrays for the x-cords of verices and the y-cords of vertices
	int* Xarr = new int [numVertices];
	int* yArr = new int[numVertices];

public:
	IrrPoly(Point*, int, GfxInfo shapeGfxInfo);
	virtual ~IrrPoly();
	virtual void Draw(GUI* pUI) const;
	virtual bool  insideShape(int x, int y);
	virtual void Save(ofstream& outfile, int id);
	virtual void Rotate();
	virtual void Resize(double size);
	virtual void Move(Point P);
	virtual void Scrample();
	virtual void  SImage(GUI* pUI);
	virtual shape* clone();
	virtual Point getUpper();
};



