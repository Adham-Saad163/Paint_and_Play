#pragma once
#include "Shapes/Shape.h"


class ColorPalette : public shape
{
public:
	ColorPalette(GfxInfo shapeGfxInfo);
	virtual ~ColorPalette();
	virtual void Draw(GUI* pUI) const;
	virtual void Save(ofstream& outfile, int id);
};
