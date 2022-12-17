#include "Triangle.h"
#include<cmath>


Triangle::Triangle(Point P1, Point P2, Point P3, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}
Triangle::~Triangle()
{}

double Triangle::getTriArea(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs(0.5 * ((x1 - x2) * (y1 - y3) - (x1 - x3) * (y1 - y2)));
}

bool Triangle::insideShape(int x, int y)
{
	if (getTriArea(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y) ==
		getTriArea(Corner1.x, Corner1.y, Corner2.x, Corner2.y, x, y)
		+ getTriArea(Corner1.x, Corner1.y, Corner3.x, Corner3.y, x, y)
		+ getTriArea(Corner2.x, Corner2.y, Corner3.x, Corner3.y, x, y)) {
		return true;
	}
	else
	{
		return false;
	}
}

void Triangle::Draw(GUI* pUI) const
{
	//Call Output::DrawTrangle to draw a rectangle on the screen	
	pUI->DrawTrian(Corner1, Corner2, Corner3, ShpGfxInfo);
}

void Triangle::Save(ofstream& outfile, int id)
{
	outfile << "Triangle" << "," << id << "," << Corner1.x << "," << Corner1.y << "," << Corner2.x << "," << Corner2.y << "," << Corner3.x << "," << Corner3.y << ",";
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
