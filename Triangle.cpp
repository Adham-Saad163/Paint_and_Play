#include "Triangle.h"
#include<cmath>


Triangle::Triangle(Point P1, Point P2, Point P3, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;

}

Triangle::Triangle(const Triangle* copy) :shape(copy->ShpGfxInfo)
{
	this->Corner1 = copy->Corner1;
	this->Corner2 = copy->Corner2;
	this->Corner3 = copy->Corner3;
	this->ID = copy->ID;
	
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
	outfile << "Triangle" << " " << id << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << Corner3.x << " " << Corner3.y << " ";
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
void Triangle::Rotate()
{
	double CenterX = (Corner1.x + Corner2.x + Corner3.x) / 3;
	double CenterY = (Corner1.y + Corner2.y + Corner3.y) / 3;
	int Temp1x = Corner1.x;
	int Temp1y = Corner1.y;
	int Temp2x = Corner2.x;
	int Temp2y = Corner2.y;
	int Temp3x = Corner3.x;
	int Temp3y = Corner3.y;
	Corner1.x = -Temp1y + CenterX + CenterY;
	Corner1.y = Temp1x - CenterX + CenterY;
	Corner2.x = -Temp2y + CenterX + CenterY;
	Corner2.y = Temp2x - CenterX + CenterY;
	Corner3.x = -Temp3y + CenterX + CenterY;
	Corner3.y = Temp3x - CenterX + CenterY;
}
void Triangle::Resize(double size)
{
	double CenterX = (Corner1.x + Corner2.x + Corner3.x) / 3;
	double CenterY = (Corner1.y + Corner2.y + Corner3.y) / 3;
	int Temp1x = Corner1.x;
	int Temp1y = Corner1.y;
	int Temp2x = Corner2.x;
	int Temp2y = Corner2.y;
	int Temp3x = Corner3.x;
	int Temp3y = Corner3.y;
	Corner1.x = size * Temp1x - size * CenterX + CenterX;
	Corner1.y = size * Temp1y - size * CenterY + CenterY;
	Corner2.x = size * Temp2x - size * CenterX + CenterX;
	Corner2.y = size * Temp2y - size * CenterY + CenterY;
	Corner3.x = size * Temp3x - size * CenterX + CenterX;
	Corner3.y = size * Temp3y - size * CenterY + CenterY;
}
void Triangle::Move(Point P)
{
	double CenterX = (Corner1.x + Corner2.x + Corner3.x) / 3;
	double CenterY = (Corner1.y + Corner2.y + Corner3.y) / 3;
	double dx = P.x- CenterX ;
	double dy =  P.y-CenterY;
	int Temp1x = Corner1.x;
	int Temp1y = Corner1.y;
	int Temp2x = Corner2.x;
	int Temp2y = Corner2.y;
	int Temp3x = Corner3.x;
	int Temp3y = Corner3.y;
	Corner1.x = Temp1x + dx;
	Corner1.y = Temp1y + dy;
	Corner2.x = Temp2x + dx;
	Corner2.y = Temp2y +dy;
	Corner3.x = Temp3x + dx;
	Corner3.y = Temp3y +dy;
}
void Triangle::Scrample()
{
	
	int temp1 = (rand() % 1000);
	int temp2 = (rand() % 500);
	double CenterX = (Corner1.x + Corner2.x + Corner3.x) / 3;
	double CenterY = (Corner1.y + Corner2.y + Corner3.y) / 3;
	double dx = temp1 - CenterX;
	double dy = temp2 - CenterY;
	int Temp1x = Corner1.x;
	int Temp1y = Corner1.y;
	int Temp2x = Corner2.x;
	int Temp2y = Corner2.y;
	int Temp3x = Corner3.x;
	int Temp3y = Corner3.y;
	Corner1.x = Temp1x + dx;
	Corner1.y = Temp1y + dy;
	Corner2.x = Temp2x + dx;
	Corner2.y = Temp2y + dy;
	Corner3.x = Temp3x + dx;
	Corner3.y = Temp3y + dy;
}
void Triangle::SImage(GUI* pUI) 
{
	pUI->StickImage(Image, Corner1.x, Corner1.y, 200, 200);
}

void Triangle::zoom(double scale, int x, int y)
{
	Corner1.x = (Corner1.x * scale) - (scale * x) + x;
	Corner1.y = (Corner1.y * scale) - (scale * y) + y;
	Corner2.x = (Corner2.x * scale) - (scale * x) + x;
	Corner2.y = (Corner2.y * scale) - (scale * y) + y;
	Corner3.x = (Corner3.x * scale) - (scale * x) + x;
	Corner3.y = (Corner3.y * scale) - (scale * y) + y;
}

shape* Triangle::clone()
{
	shape* newShape = new Triangle(*this);

	return newShape;
}

Point Triangle::getUpper()
{
	return Corner1;
}

void Triangle::hideShape(GUI* pUI)
{
	pUI->StickImage(Image, Corner1.x, Corner1.y, 200, 200);
}