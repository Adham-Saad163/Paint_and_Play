#include "Rect.h"

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
Rect::Rect(const Rect* copy) :shape(copy->ShpGfxInfo)
{
	this->Corner1 = copy->Corner1;
	this->Corner2 = copy->Corner2;
	this->ID = copy->ID;
}

Rect::~Rect()
{}

void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}

bool Rect::insideShape(int x, int y)
{
	return((x >= Corner1.x && x <= Corner2.x) || (x <= Corner1.x && x >= Corner2.x))
		&& ((y >= Corner1.y && y <= Corner2.y) || (y <= Corner1.y && y >= Corner2.y));
}

void Rect::Save(ofstream& outfile, int id)
{
	outfile << "RECT" << " " << id << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " ";
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
void Rect::Rotate()
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
void Rect::Resize(double size)
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
void Rect::Move(Point P)
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
void Rect::Scrample()
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
void Rect::SImage(GUI* pUI)
{
	pUI->StickImage(Image, Corner1.x, Corner1.y, 200, 200);
}

void Rect::zoom(double scale, int x, int y)
{
	Corner1.x = (Corner1.x * scale) - (scale * x) + x;
	Corner1.y = (Corner1.y * scale) - (scale * y) + y;
	Corner2.x = (Corner2.x * scale) - (scale * x) + x;
	Corner2.y = (Corner2.y * scale) - (scale * y) + y;
}


shape* Rect::clone()
{
	shape* newShape = new Rect(*this);

	return newShape;
}

Point Rect::getUpper()
{
	return Corner1;
}
