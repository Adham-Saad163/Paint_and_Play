#include "SImage.h"

SImage::SImage(Point p,int w,int h) 
{
	P1=p;
	width = w;
	height = h;
	Image = "images\\MenuIcons\\Menu_Stick_Image.jpg";
}


SImage::~SImage()
{}
void SImage::Draw(GUI* pUI) const
{
	pUI->StickImage(Image,P1.x, P1.y, width, height);
}

/*void SImage::Save(ofstream& outfile, int id)
{
}




void SImage::Rotate()
{

}
void SImage::Resize(double size)
{

}
void SImage::Move()
{

}*/
bool SImage::insideShape(int x, int y)
{
	return false;
}