#include "Line.h"
#include<cmath>

Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Line::~Line()
{}

void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawLine to draw a Line on the screen	
	pUI->DrawLi(Corner1, Corner2, ShpGfxInfo);
}

void Line::Save(ofstream& outfile, int id)
{
	outfile << "Line" << " " << id << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " ";
	outfile << (int)ShpGfxInfo.DrawClr.ucRed << " " << (int)ShpGfxInfo.DrawClr.ucGreen << " " << (int)ShpGfxInfo.DrawClr.ucBlue << " ";

	if (GetGfxinfo().isFilled)
	{
		outfile << (int)ShpGfxInfo.FillClr.ucRed << " " << (int)ShpGfxInfo.FillClr.ucGreen << " " << (int)ShpGfxInfo.FillClr.ucBlue << endl;
	}
	else
	{
		outfile << "NO_FILL" << endl;
	}
}

bool Line::insideShape(int x, int y)
{
	double distance = sqrt(pow(Corner2.x - Corner1.x, 2) + pow(Corner2.y - Corner1.y, 2));
	double d1 = sqrt(pow(Corner2.x - x, 2) + pow(Corner2.y - y, 2));
	double d2 = sqrt(pow(Corner1.x - x, 2) + pow(Corner1.y - y, 2));

	if ((distance * 1.0005) >= (d1 + d2))
	{
		return true;
	}
	else
	{
		return false;
	}
}
