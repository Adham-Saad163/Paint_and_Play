#include "opAddColorPalette.h"
#include "ColorPalette.h"
#include "operations/operation.h"
#include "controller.h"
#include "GUI/GUI.h"

opAddColorPalette::opAddColorPalette(controller* pCont) :operation(pCont)
{}
opAddColorPalette::~opAddColorPalette()
{}

//Execute the operation
void opAddColorPalette::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	double Red = 0, Green = 0, Blue = 0; // Shades or RGB of the color

	// Display color palette on screen to choose a color
	pUI->DrawColorPalette();
	pUI->PrintMessage("Choose color:");
	pUI->ClearStatusBar();

	GfxInfo ColorPaletteGfxInfo;
	ColorPalette* R = new ColorPalette(ColorPaletteGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	// Creating a window for color palette 
	pGr->Addshape(R);

	Point p1;
	pUI->GetPointClicked(p1.x, p1.y);
	pUI->PickColor(p1.x, p1.y, Red, Green, Blue);
	Red *= 255;
	Green *= 255;
	Blue *= 255;

	pGr->setColor(Red, Green, Blue);
	pUI->setFillcolor(pGr->getColor());
	pUI->PrintMessage("New color is picked!");
	pGr->RemoveShape(R);
}

void opAddColorPalette::Undo() {}
void opAddColorPalette::Redo() {}