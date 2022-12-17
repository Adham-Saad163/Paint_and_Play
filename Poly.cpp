#include "Poly.h"
#include <math.h>
#include <corecrt_math_defines.h>

Poly::Poly(Point input_point1, Point input_center, int input_numVertices, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	point1.x = input_point1.x;
	point1.y = input_point1.y;
	center.x = input_center.x;
	center.y = input_center.y;
	numVertices = input_numVertices;



	// calculate the distance between the first point and the center
	double distance = sqrt(pow((point1.x - center.x), 2) + pow((point1.y - center.y), 2));
	
	for (int i = 0;i < numVertices;i++) {
		double xCoord = center.x + distance * cos(i * 2 * M_PI / numVertices);
		double yCoord = center.y + distance * sin(i * 2 * M_PI / numVertices);
		xArr[i] = xCoord;
		yArr[i] = yCoord;
	}
}

Poly::~Poly()
{}

void Poly::Draw(GUI* pUI) const
{

	//Call Output::DrawPolygon to draw a Polygon on the screen	
	pUI->DrawPoly(xArr, yArr, numVertices, ShpGfxInfo);
}

bool Poly::insideShape(int x, int y)
{
	return false;
}

void Poly::Save(ofstream& outfile, int id)
{
	outfile << "Poly" << "," << id << "," << numVertices << "," << point1.x << "," << point1.y << "," << center.x << "," << center.y << ",";
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