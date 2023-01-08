#include "shape.h"

shape::shape(GfxInfo shapeGfxInfo)
{ 
	ShpGfxInfo = shapeGfxInfo;	//Default status is non-filled.
}
 
void shape::SetSelected(bool s)
{	ShpGfxInfo.isSelected = s; }

bool shape::IsSelected() const
{	return ShpGfxInfo.isSelected; }

void shape::ChngDrawClr(color Dclr)
{	ShpGfxInfo.DrawClr = Dclr; }

void shape::ChngFillClr(color Fclr)
{	
	ShpGfxInfo.isFilled = true;
	ShpGfxInfo.FillClr = Fclr; 
}

GfxInfo shape::GetGfxinfo()const { return ShpGfxInfo; }

void shape::setIsfilled(bool a)
{
	ShpGfxInfo.isFilled = a;
}

void shape::SetHiden(bool s)
{
	ShpGfxInfo.IsHiden = s;
}

bool shape::IsHiden()
{
	return ShpGfxInfo.IsHiden;
}