#include "ColorPalette.h"


ColorPalette::~ColorPalette()
{}


void ColorPalette::Draw(GUI* pUI) const
{
	pUI->DrawColorPalette();
}

ColorPalette::ColorPalette(GfxInfo shapeGfxInfo) :shape(shapeGfxInfo) 
{}


