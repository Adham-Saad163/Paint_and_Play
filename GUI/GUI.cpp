#include "GUI.h"

GUI::GUI()
{
	//Initialize user interface parameters
	InterfaceMode = MODE_DRAW;

	width = 1300;
	height = 700;
	wx = 5;
	wy = 5;


	StatusBarHeight = 50;
	ToolBarHeight = 50;
	MenuIconWidth = 50;

	DrawColor = BLUE;	//default Drawing color
	FillColor = GREEN;	//default Filling color
	MsgColor = BLACK;		//Messages color
	BkGrndColor = WHITE;	//Background color
	HighlightColor = MAGENTA;	//This color should NOT be used to draw shapes. use if for highlight only
	StatusBarColor = LIGHTSEAGREEN;
	PenWidth = 3;	//default width of the shapes frames


	//Create the output window
	pWind = CreateWind(width, height, wx, wy);
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - PAINT ^ ^ PLAY - - - - - - - - - -");

	CreateDrawToolBar();
	CreateStatusBar();
}




//======================================================================================//
//								Input Functions										//
//======================================================================================//
void GUI::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}
window* GUI::DetectMouse()
{
	return this->pWind;
}
string GUI::GetSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if( Label.size() > 0)	
				Label.resize(Label.size() - 1);
			else
				Key = '\0';		
		else
			Label += Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired operation
operationType GUI::GetUseroperation() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu icon was clicked
			//==> This assumes that menu icons are lined up horizontally <==
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder)
			{
			case ICON_RECT: return DRAW_RECT;
			case ICON_CIRC: return DRAW_CIRC;
			case ICON_LINE: return DRAW_LINE;
			case ICON_TRI: return DRAW_TRI;
			case ICON_SQUARE: return DRAW_SQ;   //Select Shape
			case ICON_POLY: return DRAW_POLY;
			case ICON_IRRPOLY: return DRAW_IRRPOLY;
			case ICON_COLOR_PALETTE: return DRAW_COLOR_PALETTE;
			case ICON_STICK:return STICK_I;

			case ICON_FILL: return CHNG_FILL_CLR;
			case ICON_PEN_COLOR: return CHANGE_PEN_COLOR;

			case ICON_SELECT: return SELECT;
			case ICON_PLAY: return TO_PLAY;
			case ICON_DELETE: return DEL;
			case ICON_SAVE: return SAVE;
			case ICON_LOAD: return LOAD;

			case ICON_UNDO: return UNDO;
			case ICON_REDO: return REDO;
			case ICON_ROTATE: return ROTATE;
			case ICON_RESIZE: return RESIZE;
			case ICON_MOVE: return MOVE;
			case ICON_SCRAMBLE: return SCRAMBLE;
			case ICON_ZOOMIN: return ZOOMIN;
			case ICON_ZOOMOUT: return ZOOMOUT;
			case ICON_EXIT: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}



	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding operation
		int x, y;
		pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
		if (y >= 0 && y < ToolBarHeight)
		{

			int ClickedIconOrder = (x / MenuIconWidth);
			switch (ClickedIconOrder)
			{
			case ICON_DRAW: return TO_DRAW;
			case ICON_EXIT: return EXIT;


			//case ICON_START: return   ;
			//case ICON_RESTART: return  ;
			//case ICON_HIDE: return   ;
			//case ICON_UNHIDE: return   ;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
	}
}
////////////////////////////////////////////////////



//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(BkGrndColor);
	pW->SetPen(BkGrndColor, 1);
	pW->DrawRectangle(0, ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white Rectangle
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}


void GUI::ClearToolBar() const
{
	// Clear Tool bar by drawing a filled white rectangle
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(5, 5, width, -ToolBarHeight);
	pWind->DrawRectangle(5, 5, width, ToolBarHeight);
}



//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar() 
{
	InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu icon
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuIcon
	string MenuIconImages[DRAW_ICON_COUNT];
	MenuIconImages[ICON_RECT] = "images\\MenuIcons\\Menu_Rect.jpg";
	MenuIconImages[ICON_CIRC] = "images\\MenuIcons\\Menu_Circ.jpg";
	MenuIconImages[ICON_TRI] = "images\\MenuIcons\\Menu_Triangle.jpg";
	MenuIconImages[ICON_LINE] = "images\\MenuIcons\\Menu_Line.jpg";
	MenuIconImages[ICON_SQUARE] = "images\\MenuIcons\\Menu_Square.jpg";
	MenuIconImages[ICON_POLY] = "images\\MenuIcons\\Menu_Poly.jpg";
	MenuIconImages[ICON_IRRPOLY] = "images\\MenuIcons\\Menu_IrrPoly.jpg";

	MenuIconImages[ICON_STICK] = "images\\MenuIcons\\Menu_Stick_Image.jpg";
	MenuIconImages[ICON_SELECT] = "images\\MenuIcons\\Menu_Select.jpg";
	MenuIconImages[ICON_COLOR_PALETTE] = "images\\MenuIcons\\Menu_Color_Palette.jpg";
	MenuIconImages[ICON_FILL] = "images\\MenuIcons\\Menu_Fill.jpg";
	MenuIconImages[ICON_PLAY] = "images\\MenuIcons\\Menu_Play.jpg";
	MenuIconImages[ICON_DELETE] = "images\\MenuIcons\\Menu_Delete.jpg";
	MenuIconImages[ICON_SAVE] = "images\\MenuIcons\\Menu_Save.jpg";
	MenuIconImages[ICON_LOAD] = "images\\MenuIcons\\Menu_Load.jpg";
	MenuIconImages[ICON_UNDO] = "images\\MenuIcons\\Menu_Undo.jpg";
	MenuIconImages[ICON_REDO] = "images\\MenuIcons\\Menu_Redo.jpg";

	MenuIconImages[ICON_PEN_COLOR] = "images\\MenuIcons\\Menu_Pen_Color.jpg";
	MenuIconImages[ICON_ROTATE] = "images\\MenuIcons\\Menu_Rotate.jpg";
	MenuIconImages[ICON_RESIZE] = "images\\MenuIcons\\Menu_Resize.jpg";
	MenuIconImages[ICON_MOVE] = "images\\MenuIcons\\Menu_Move.jpg";
	MenuIconImages[ICON_SCRAMBLE] = "images\\MenuIcons\\Menu_Scrample.jpg";

	MenuIconImages[ICON_ZOOMIN] = "images\\MenuIcons\\Menu_Zoom_In.jpg";
	MenuIconImages[ICON_ZOOMOUT] = "images\\MenuIcons\\Menu_Zoom_Out.jpg";
	MenuIconImages[ICON_EXIT] = "images\\MenuIcons\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu icon and add it to the list
	//Draw menu icon one image at a time
	for (int i = 0; i < DRAW_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::CreatePlayToolBar() 
{
	InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu

	string MenuIconImages[DRAW_ICON_COUNT];


	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);

	MenuIconImages[ICON_START] = "images\\MenuIcons\\Menu_Start.jpg";
	MenuIconImages[ICON_RESTART] = "images\\MenuIcons\\Menu_Restart.jpg";
	MenuIconImages[ICON_HIDE] = "images\\MenuIcons\\Menu_Hide.jpg";
	MenuIconImages[ICON_UNHIDE] = "images\\MenuIcons\\Menu_Unhide.jpg";
	MenuIconImages[ICON_DRAW] = "images\\MenuIcons\\Menu_Draw.jpg";



	//Draw menu icon one image at a time
	for (int i = 0;i < PLAY_ICON_COUNT;i++) {
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);
	}

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearDrawArea() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, height - (int)(0.75 * StatusBarHeight), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{
	return DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntFillColor() const	//get current filling color
{
	return FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int GUI::getCrntPenWidth() const		//get current pen width
{
	return PenWidth;
}

//======================================================================================//
//								shapes Drawing Functions								//
//======================================================================================//

void GUI::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	if (RectGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}


void GUI::DrawTrian(Point P1, Point P2, Point P3, GfxInfo TrianGfxInfo)const
{
	color DrawingClr;
	if (TrianGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = TrianGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TrianGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (TrianGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TrianGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}



void GUI::DrawLi(Point P1, Point P2, GfxInfo LiGfxInfo) const
{
	color DrawingClr;
	if (LiGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = LiGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, LiGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (LiGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(LiGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);

}

void GUI::DrawCircle(Point P1, double Radius, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	if (RectGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	
	pWind->DrawCircle(P1.x, P1.y, Radius, style);

}



void GUI::DrawSq(Point P1, Point P2, const GfxInfo SqGfxInfo) const
{
	color DrawingClr;
	if (SqGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = SqGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, SqGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (SqGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SqGfxInfo.FillClr);
	}
	else
		style = FRAME;
	if (sqrt(pow(P2.y - P1.y, 2)) > sqrt(pow(P2.x - P1.x, 2)))
	{
		//here the calculation of the 4 vertices of square
		double x1 = P1.x, y1 = P1.y;//P1
		double x2 = P1.x, y2 = P2.y;//P2
		double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));//distance between P1&P2
		double x3 = P1.x + distance, y3 = P1.y;//P3
		double x4 = P1.x + distance, y4 = P2.y;//P4
		//link between 4 points using DrawLine function
		pWind->DrawLine(x1, y1, x2, y2, style);
		pWind->DrawLine(x1, y1, x3, y3, style);
		pWind->DrawLine(x2, y2, x4, y4, style);
		pWind->DrawLine(x3, y3, x4, y4, style);
	}
	if (sqrt(pow(P2.x - P1.x, 2)) > sqrt(pow(P2.y - P1.y, 2)))
	{
		//here the calculation of the 4 vertices of square
		double x1 = P1.x, y1 = P1.y;//P1
		double x2 = P2.x, y2 = P1.y;//P2
		double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));//distance between P1&P2
		double x3 = P1.x, y3 = P1.y + distance;//P3
		double x4 = P2.x, y4 = P1.y + distance;//P4
		//link between 4 points using DrawLine function
		pWind->DrawLine(x1, y1, x2, y2, style);
		pWind->DrawLine(x1, y1, x3, y3, style);
		pWind->DrawLine(x2, y2, x4, y4, style);
		pWind->DrawLine(x3, y3, x4, y4, style);
	}


};


void GUI::StickImage(string image, int x1, int y1, int x2, int y2)
{
	pWind->DrawImage(image, x1, y1, x2, y2);
}

//DrawPolygon(const int* ipX, const int* ipY, const int iVertices, const drawstyle dsStyle) 
void GUI::DrawPoly(int* xArr, int* yArr, int numVertices,  GfxInfo PolyGfxInfo) const
{
	color DrawingClr;
	if (PolyGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = PolyGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, PolyGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (PolyGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(PolyGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawPolygon(xArr, yArr, numVertices, style);

}


void GUI::setFillcolor(color newColor)
{
	FillColor = newColor;
	pWind->SetBrush(newColor);
}


void GUI::setDrawColor(color newColor)
{
	DrawColor = newColor;
}


// Function to draw color palette 
void GUI::DrawColorPalette() 
{
	string path = "images\\MenuIcons\\Menu_Color_Palette.jpg";
	pWind->DrawImage(path, 400, 50, 300, 250);
}


color GUI::GetColorPalette(const int x, const int y) 
{
	pWind->GetColor(x, y);
	DrawColor = pWind->GetColor(x, y);
	return DrawColor;
}

// Function to pick color
void GUI::PickColor(int x, int y, double& Red, double& Green, double& Blue) 
{
	pWind->GetColor(x, y, Red, Green, Blue);
}

void GUI::waitKeyPress(char& Key) const
{
	pWind->FlushKeyQueue();
	pWind->WaitKeyPress(Key); // Get the keyboard button clicked
}
//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}

