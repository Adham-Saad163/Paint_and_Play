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

ColorPalette::ColorPalette(GfxInfo shapeGfxInfo) :shape(shapeGfxInfo) 
{}


