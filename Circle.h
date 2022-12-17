#pragma once
#include"Shapes/Shape.h"
class Circle : public shape
{
private:
	Point Center;
	Point Radius;
public:
	Circle(Point, Point, GfxInfo shapeGfxInfo);
	virtual bool insideShape(int x, int y);
	virtual ~Circle();
	virtual void Draw(GUI* pUI) const;
	double getRadius(Point P1, Point P2);
	virtual void Save(ofstream& outfile,int id);
};

