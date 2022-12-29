#include "Circle.h"
Circle::Circle(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Point1 = P1;
	Point2 = P2;
	Radius= sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2));
};

double Circle::getRadius(Point P1, Point P2)//get radius of circle
{
	return sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2));
}

Circle::~Circle()
{}

bool Circle::insideShape(int x, int y)//to check if the point in the circle
{
	if (sqrt(pow(x - Point1.x, 2) + pow(y - Point1.y, 2)) <= (getRadius(Point1, Point2))) {
		return true;
	}
	else {
		return false;
	}
}


void Circle::Draw(GUI* pUI) const
{
	//Call Output::DrawCircle to draw a Circle on the screen	
	pUI->DrawCircle(Point1, Radius, ShpGfxInfo);
}

void Circle::Save(ofstream& outfile, int id)
{
	outfile << "Circle" << " " << id << " " << Point1.x << " " << Point1.y << " " << Point2.x << " " << Point2.y << " ";
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
void Circle::Rotate()
{

}
void Circle::Resize(double size)
{
	double Temp = Radius;
	Radius = size * Temp;
}
void Circle::Move(Point P)
{
	double Temp1 = P.x;
	double Temp2 = P.y;
	Point1.x = Temp1;
	Point1.y = Temp2;
}

