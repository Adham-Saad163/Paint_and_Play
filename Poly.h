#pragma once
#include "Shapes/Shape.h"

class Poly : public shape
{
private:
	Point point1;
	Point center;
	int numVertices = 0;
	

	// making two dynamic arrays for the x-cords of verices and the y-cords of vertices
	int* xArr = new int[numVertices];
	int* yArr = new int[numVertices];

public:
	Poly(Point, Point, int, GfxInfo shapeGfxInfo);
	
	virtual ~Poly();
	virtual void Draw(GUI* pUI) const;
	virtual bool  insideShape(int x, int y);
	virtual void Save(ofstream& outfile, int id);
	virtual void Rotate();
	virtual void Resize(double size);
	virtual void Move(Point P);
	virtual void Scrample();
	virtual void  SImage(GUI* pUI);

	void zoom(double scale, int x, int y) override;

	virtual shape* clone();
	virtual Point getUpper();
};



