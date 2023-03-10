#pragma once
#include"Shapes/Shape.h"
class Circle : public shape
{
private:
	Point Point1;
	Point Point2;
	double Radius = sqrt(pow(Point2.x - Point1.x, 2) + pow(Point2.y - Point1.y, 2));
	string Image = "images\\MenuIcons\\Menu_Stick_Image.jpg";
public:
	Circle(Point, Point, GfxInfo shapeGfxInfo);
	Circle(const Circle* copy);
	virtual bool insideShape(int x, int y);
	virtual ~Circle();
	virtual void Draw(GUI* pUI) const;
	double getRadius(Point P1, Point P2);
	virtual void Save(ofstream& outfile,int id);
	virtual void Rotate();
	virtual void Resize(double size);
	virtual void Move(Point P);
	virtual void Scrample();
	virtual void  SImage(GUI* pUI);
	
	void zoom(double scale, int x, int y) override;

	int* getshapeparamters();
	virtual shape* clone();
	virtual Point getUpper();
	void hideShape(GUI* pUI) override;
	//virtual void Load(ifstream& Infile);
};

