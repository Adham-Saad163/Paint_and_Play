#pragma once
#include "shape.h"

class Rect : public shape
{
private:
	Point Corner1;	
	Point Corner2;
	string Image = "images\\MenuIcons\\Menu_Stick_Image.jpg";
public:
	Rect(Point , Point, GfxInfo shapeGfxInfo );
	Rect(const Rect* copy);
	virtual ~Rect();
	virtual void Draw(GUI* pUI) const;
	virtual bool  insideShape(int x, int y);
	virtual void Save(ofstream& outfile, int id);
	virtual void Rotate();
	virtual void Resize(double size);
	virtual void Move(Point P);
	virtual void Scrample();
	virtual void  SImage(GUI* pUI);

	virtual void zoom(double scale, int x, int y) override;

	virtual shape* clone();
	virtual Point getUpper();

	void hideShape(GUI* pUI) override;
	//virtual void Load(ifstream& Infile);
};

