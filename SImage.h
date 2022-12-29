#pragma once
#include"GUI/GUI.h"
class SImage 
{
private:
	string Image;
	Point P1;
	int width;
	int height;
public:
	 bool  insideShape(int x, int y);
	SImage(Point p, int w,int h);
	virtual ~SImage();
	 void Draw(GUI* pUI) const;
	//virtual void Save(ofstream& outfile, int id);
	//virtual void Rotate();
	//virtual void Resize(double size);
	//virtual void Move();
};

