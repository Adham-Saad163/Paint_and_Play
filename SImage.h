#pragma once
#include "Shapes/Shape.h"

class SImage : public shape
{
private:
	string Image;
	Point P1;
	int width;
	int height;
public:
	virtual bool  insideShape(int x, int y);
	SImage(Point p, int w,int h, GfxInfo shapeGfxInfo);
	virtual ~SImage();
	virtual void Draw(GUI* pUI) const;
	virtual void Save(ofstream& outfile, int id);
};

