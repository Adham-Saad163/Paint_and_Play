#pragma once
#include "Shapes/Shape.h"
class Line : public shape
{
private:
	Point Corner1;
	Point Corner2;
public:
	virtual bool  insideShape(int x, int y);
	Line(Point Corner1, Point Corner2, GfxInfo shapeGfxInfo);
	virtual ~Line();
	virtual void Draw(GUI* pUI) const;
	virtual void Save(ofstream& outfile, int id);
	virtual void Rotate();
	virtual void Resize(double size);
	virtual void Move(Point P);
	virtual void Scrample();
};


