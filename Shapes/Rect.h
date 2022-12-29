#pragma once
#include "shape.h"

class Rect : public shape
{
private:
	Point Corner1;	
	Point Corner2;
public:
	Rect(Point , Point, GfxInfo shapeGfxInfo );
	virtual ~Rect();
	virtual void Draw(GUI* pUI) const;
	virtual bool  insideShape(int x, int y);
	virtual void Save(ofstream& outfile, int id);
	virtual void Rotate();
	virtual void Resize(double size);
	virtual void Move(Point P);

};

