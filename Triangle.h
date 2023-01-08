#pragma once
#include "Shapes/Shape.h"

class Triangle :public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
	string Image= "images\\MenuIcons\\Menu_Stick_Image.jpg";
public:
	double  getTriArea(int x1, int y1, int x2, int y2, int x3, int y3);
	virtual bool  insideShape(int x, int y);
	Triangle(Point P1, Point P2, Point P3, GfxInfo shapeGfxInfo);
	virtual ~Triangle();
	virtual void Draw(GUI* pUI) const;
	virtual void Save(ofstream& outfile, int id);
	virtual void Rotate();
	virtual void Resize(double size);
	virtual void Move(Point P);
	virtual void Scrample() ;
	virtual void  SImage(GUI* pUI) ;

	void zoom(double scale, int x, int y) override;
};

