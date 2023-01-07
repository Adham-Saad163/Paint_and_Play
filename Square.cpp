#include "Square.h"
#include<cmath>
Square::Square(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
void Square::setSquareV(Point P1, Point P2)
{
	if (sqrt(pow(P2.y - P1.y, 2)) > sqrt(pow(P2.x - P1.x, 2)))
	{
		//here the calculation of the 4 vertices of square
		x1 = P1.x, y1 = P1.y;//P1
		x2 = P1.x, y2 = P2.y;//P2
		double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));//distance between P1&P2
		x3 = P1.x + distance, y3 = P1.y;//P3
		x4 = P1.x + distance, y4 = P2.y;//P4
	}
	if (sqrt(pow(P2.x - P1.x, 2)) > sqrt(pow(P2.y - P1.y, 2)))
	{
		//here the calculation of the 4 vertices of square
		x1 = P1.x, y1 = P1.y;//P1
		x2 = P2.x, y2 = P1.y;//P2
		double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));//distance between P1&P2
		x3 = P1.x, y3 = P1.y + distance;//P3
		x4 = P2.x, y4 = P1.y + distance;//P4

	}
}

Square::~Square()
{}


bool Square::insideShape(int x, int y)
{
	if (sqrt(pow(Corner2.y - Corner1.y, 2)) > sqrt(pow(Corner2.x - Corner1.x, 2)))
	{
		//here the calculation of the 4 vertices of square
		x1 = Corner1.x, y1 = Corner1.y;//P1
		x2 = Corner1.x, y2 = Corner2.y;//P2
		double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));//distance between P1&P2
		x3 = Corner1.x + distance, y3 = Corner1.y;//P3
		x4 = Corner1.x + distance, y4 = Corner2.y;//P4
	}
	if (sqrt(pow(Corner2.x - Corner1.x, 2)) > sqrt(pow(Corner2.y - Corner1.y, 2)))
	{
		//here the calculation of the 4 vertices of square
		x1 = Corner1.x, y1 = Corner1.y;//P1
		x2 = Corner2.x, y2 = Corner1.y;//P2
		double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));//distance between P1&P2
		x3 = Corner1.x, y3 = Corner1.y + distance;//P3
		x4 = Corner2.x, y4 = Corner1.y + distance;//P4

	}

	return((x >= Corner1.x && x <= x4) || (x <= Corner1.x && x >= x4))
		&& ((y >= Corner1.y && y <= y4) || (y <= Corner1.y && y >= y4));
}

void Square::Draw(GUI* pUI) const
{
	//Call Output::DrawSq to draw a Square on the screen	
	pUI->DrawSq(Corner1, Corner2, ShpGfxInfo);
}
void Square::Save(ofstream& outfile, int id)
{
	outfile << "Squar" << " " << id << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " ";
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
void Square::Rotate()
{

}
void Square::Resize(double size)
{
	double CenterX = (Corner1.x + Corner2.x) / 2;
	double CenterY = (Corner1.y + Corner2.y) / 2;
	int Temp1x = Corner1.x;
	int Temp1y = Corner1.y;
	int Temp2x = Corner2.x;
	int Temp2y = Corner2.y;
	Corner1.x = size * Temp1x - size * CenterX + CenterX;
	Corner1.y = size * Temp1y - size * CenterY + CenterY;
	Corner2.x = size * Temp2x - size * CenterX + CenterX;
	Corner2.y = size * Temp2y - size * CenterY + CenterY;
}
void Square::Move(Point P)
{
	double CenterX = (Corner1.x + Corner2.x ) / 2;
	double CenterY = (Corner1.y + Corner2.y ) / 2;
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
void Square::Scrample()
{
	
	int temp1 = (rand() % 1000);
	int temp2 = (rand() % 500);
	double CenterX = (Corner1.x + Corner2.x ) / 2;
	double CenterY = (Corner1.y + Corner2.y ) / 2;
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
void Square::SImage(GUI* pUI)
{
	pUI->StickImage(Image, Corner1.x, Corner1.y, 200, 200);
}