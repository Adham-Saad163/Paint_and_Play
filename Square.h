#pragma once
#include "Shapes/shape.h"

class Square : public shape
{
private:
	Point Corner1;
	Point Corner2;
	int x1, x2, x3, x4, y1, y2, y3, y4;
	string Image = "images\\MenuIcons\\Menu_Stick_Image.jpg";
public:
	double  getSquareArea(int x1, int y1, int x2, int y2);
	void setSquareV(Point P1, Point P2);
	virtual bool  insideShape(int x, int y);
	Square(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Square();
	virtual void Draw(GUI* pUI) const;
	virtual void Save(ofstream& outfile, int id);
	virtual void Rotate();
	virtual void Resize(double size);
	virtual void Move(Point P);
	virtual void Scrample();
	virtual void  SImage(GUI* pUI);

	void zoom(double scale, int x, int y) override;
	void hideShape(GUI* pUI) override;
};

