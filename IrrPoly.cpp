#include "IrrPoly.h"
#include <math.h>
#include <corecrt_math_defines.h>


IrrPoly::IrrPoly(Point* input_yArr, int input_numVertices, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Arr = input_yArr;
	numVertices = input_numVertices;
}

IrrPoly::~IrrPoly()
{}

void IrrPoly::Draw(GUI* pUI) const
{
	for (int i = 0;i < numVertices;i++)
	{
		Xarr[i] = Arr[i].x;
		yArr[i] = Arr[i].y;
	}

	//Call Output::DrawPolygon to draw an irregular Polygon on the screen	
	pUI->DrawPoly(Xarr,yArr, numVertices, ShpGfxInfo);
}

bool IrrPoly::insideShape(int x, int y)
{
	return false;
}

void IrrPoly::Save(ofstream& outfile, int id)
{
	outfile << "IrrPoly" << "," << id << "," << numVertices << ",";
	for (int i = 0;i < numVertices;i++)
	{
		outfile << Arr[i].x << ",";
		outfile << Arr[i].y << ",";
	}

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