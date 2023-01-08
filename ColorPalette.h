#pragma once
#include "Shapes/Shape.h"


class ColorPalette : public shape
{
public:
	ColorPalette(GfxInfo shapeGfxInfo);
	virtual ~ColorPalette();
	virtual void Draw(GUI* pUI) const;
	virtual void Save(ofstream& outfile, int id);
	virtual bool insideShape(int x, int y) ;
	virtual void Rotate();
	virtual void Resize(double size);
	virtual void Move(Point P);
	virtual void Scrample();
	virtual void  SImage(GUI* pUI);
	virtual shape* clone();
	virtual Point getUpper();

	
};
