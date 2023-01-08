#pragma once
#include "Shapes/Shape.h"
class Line : public shape
{
private:
	Point Corner1;
	Point Corner2;
	
public:
	virtual bool  insideShape(int x, int y);
	Line(Point Corner1, Point Corner2, GfxInfo shapeGfxInfo);
	Line(const Line* copy);
	virtual ~Line();
	virtual void Draw(GUI* pUI) const;
	virtual void Save(ofstream& outfile, int id);

	virtual void Rotate();
	virtual void Resize(double size);
	virtual void Move(Point P);
	virtual void Scrample();
	virtual void  SImage(GUI* pUI);

	void zoom(double scale, int x, int y) override;

	virtual shape* clone();
	virtual Point getUpper();
	void hideShape(GUI* pUI) override;
};



