#include "Rect.h"

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Rect::~Rect()
{}

void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}

bool Rect::insideShape(int x, int y)
{
	return((x >= Corner1.x && x <= Corner2.x) || (x <= Corner1.x && x >= Corner2.x))
		&& ((y >= Corner1.y && y <= Corner2.y) || (y <= Corner1.y && y >= Corner2.y));
}

void Rect::Save(ofstream& outfile, int id)
{
	outfile << "RECT" << "," << id << "," << Corner1.x << "," << Corner1.y << "," << Corner2.x << "," << Corner2.y << ",";
	outfile << (int)GetGfxinfo().DrawClr.ucRed << "," << (int)GetGfxinfo().DrawClr.ucGreen << "," << (int)GetGfxinfo().DrawClr.ucBlue << ",";

	if (GetGfxinfo().isFilled)
	{
		outfile << (int)GetGfxinfo().FillClr.ucRed << "," << (int)GetGfxinfo().FillClr.ucGreen << "," << (int)GetGfxinfo().FillClr.ucBlue << endl;
	}
	else
	{
		outfile << "NO_FILL" << endl;
	}
}