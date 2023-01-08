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
	outfile << "Poly" << " " << id << " " << numVertices << " " << point1.x << " " << point1.y << " " << center.x << " " << center.y << " ";
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
void Poly::Rotate()
{

}
void Poly::Resize(double size)
{

}
void Poly::Move(Point P)
{

}
void Poly::Scrample()
{

}
void Poly::SImage(GUI* pUI)
{
	
}

void Poly::zoom(double scale, int x, int y)
{
	for (int i = 0; i < numVertices; i++)
	{
		xArr[i] = (xArr[i] * scale) - (scale * x) + x;
		yArr[i] = (yArr[i] * scale) - (scale * y) + y;
	}
}


shape* Poly::clone()
{
	shape* newShape = new Poly(*this);

	return newShape;
}

Point Poly::getUpper()
{
	return point1;
}

void Poly::hideShape(GUI* pUI)
{

}