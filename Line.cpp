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
void Line::Rotate()
{

	double CenterX = (Corner1.x + Corner2.x) / 2;
	double CenterY = (Corner1.y + Corner2.y) / 2;
	int Temp1x = Corner1.x;
	int Temp1y = Corner1.y;
	int Temp2x = Corner2.x;
	int Temp2y = Corner2.y;
	Corner1.x = -Temp1y + CenterX + CenterY;
	Corner1.y = Temp1x - CenterX + CenterY;
	Corner2.x = -Temp2y + CenterX + CenterY;
	Corner2.y = Temp2x - CenterX + CenterY;
}
void Line::Resize(double size)
{
	double CenterX = (Corner1.x + Corner2.x) / 2;
	double CenterY = (Corner1.y + Corner2.y) / 2;
	int Temp1x = Corner1.x;
	int Temp1y = Corner1.y;
	int Temp2x = Corner2.x;
	int Temp2y = Corner2.y;
	Corner1.x = size  * Temp1x - size * CenterX  + CenterX;
	Corner1.y = size * Temp1y - size * CenterY + CenterY;
	Corner2.x = size * Temp2x - size * CenterX + CenterX;
	Corner2.y = size * Temp2y - size * CenterY + CenterY;
}
void Line::Move(Point P)
{
	double CenterX = (Corner1.x + Corner2.x) / 2;
	double CenterY = (Corner1.y + Corner2.y) / 2;
	double dx = P.x - CenterX;
	double dy = P.y - CenterY;
	int Temp1x = Corner1.x;
	int Temp1y = Corner1.y;
	int Temp2x = Corner2.x;
	int Temp2y = Corner2.y;

	Corner1.x = Temp1x + dx;
	Corner1.y = Temp1y + dy;
	Corner2.x = Temp2x + dx;
	Corner2.y = Temp2y + dy;
	 
}
void Line::Scrample()
{
	
	int temp1 = (rand() % 1000);
	int temp2 = (rand() % 500);
	double CenterX = (Corner1.x + Corner2.x) / 2;
	double CenterY = (Corner1.y + Corner2.y) / 2;
	double dx = temp1 - CenterX;
	double dy = temp2 - CenterY;
	int Temp1x = Corner1.x;
	int Temp1y = Corner1.y;
	int Temp2x = Corner2.x;
	int Temp2y = Corner2.y;

	Corner1.x = Temp1x + dx;
	Corner1.y = Temp1y + dy;
	Corner2.x = Temp2x + dx;
	Corner2.y = Temp2y + dy;
}
void Line::SImage(GUI* pUI)
{
	
}

shape* Line::clone()
{
	shape* newShape = new Line(*this);

	return newShape;
}

Point Line::getUpper()
{
	return Corner1;
}
Line::Line(const Line* copy) :shape(copy->ShpGfxInfo)
{
	this->Corner1 = copy->Corner1;
	this->Corner2 = copy->Corner2;
	this->ID = copy->ID;
	

}
