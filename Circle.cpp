#include "Circle.h"
Circle::Circle(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Center = P1;
	Radius = P2;
};

double Circle::getRadius(Point P1, Point P2)//get radius of circle
{
	return sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2));
}

Circle::~Circle()
{}

bool Circle::insideShape(int x, int y)//to check if the point in the circle
{
	if (sqrt(pow(x - Center.x, 2) + pow(y - Center.y, 2)) <= (getRadius(Center, Radius))) {
		return true;
	}
	else {
		return false;
	}
}


void Circle::Draw(GUI* pUI) const
{
	//Call Output::DrawCircle to draw a Circle on the screen	
	pUI->DrawCircle(Center, Radius, ShpGfxInfo);
}

void Circle::Save(ofstream& outfile, int id)
{
	outfile << "Circle" << " " << id << " " << Center.x << " " << Center.y << " " << Radius.x << " " << Radius.y << " ";
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