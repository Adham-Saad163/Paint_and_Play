#include "ColorPalette.h"


ColorPalette::~ColorPalette()
{}


void ColorPalette::Draw(GUI* pUI) const
{
	pUI->DrawColorPalette();
}

void ColorPalette::Save(ofstream& outfile, int id)
{
}

bool ColorPalette::insideShape(int x, int y)
{
	return false;
}

ColorPalette::ColorPalette(GfxInfo shapeGfxInfo) :shape(shapeGfxInfo) 
{}


