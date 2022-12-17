#pragma once
#include "Shapes/shape.h"

class Square : public shape
{
private:
	Point Corner1;
	Point Corner2;
	int x1, x2, x3, x4, y1, y2, y3, y4;
public:
	double  getSquareArea(int x1, int y1, int x2, int y2);
	void setSquareV(Point P1, Point P2);
	virtual bool  insideShape(int x, int y);
	Square(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Square();
	virtual void Draw(GUI* pUI) const;
	virtual void Save(ofstream& outfile, int id);
};
