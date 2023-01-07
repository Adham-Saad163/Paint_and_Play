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

void ColorPalette::Rotate()
{

}
void ColorPalette::Resize(double size)
{

}
void ColorPalette::Move(Point P)
{

}
void ColorPalette::Scrample()
{

}
void ColorPalette::SImage(GUI* pUI)
{

}
