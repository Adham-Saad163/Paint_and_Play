#pragma once
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"
#include <string>
using namespace std;

struct Point	//To be used for shapes points
{
	int x, y;
};

struct GfxInfo	//Graphical info common for all shapes (you may add more members)
{
	color DrawClr;	//Draw color of the shape
	color FillClr;	//Fill color of the shape
	bool isFilled;	//shape Filled or not
	int BorderWdth;	//Width of shape borders
	bool isSelected;	//true if the shape is selected.
};




class GUI
{
	enum GUI_MODE	//Graphical user interface mode
	{
		MODE_DRAW,	//Drawing mode (startup mode)
		MODE_PLAY	//Playing mode
	};

	enum DrawMenuIcon //The icons of the Draw menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_RECT,		//Recangle icon in menu
		ICON_CIRC,		//Circle icon in menu
		ICON_LINE,      //Line icon in menu
		ICON_TRI,       //Triangle icon in menu
		ICON_SQUARE,    //Square icon in menu
		ICON_POLY,
		ICON_IRRPOLY,

		ICON_COLOR_PALETTE,
		ICON_FILL,
		ICON_STICK,		//stick image icon
		ICON_SELECT,
		ICON_DELETE,
		ICON_SAVE,
		ICON_LOAD,
		ICON_PLAY,
		ICON_ROTATE,
		ICON_RESIZE,
		ICON_MOVE,
		ICON_SCRAMBLE,
		//TODO: Add more icons names here

		ICON_EXIT,		//Exit icon

		DRAW_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};

	enum PlayMenuIcon //The icons of the Play menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		//TODO: Add more icons names here


		ICON_START,
		ICON_RESTART,
		ICON_HIDE,
		ICON_UNHIDE,
		ICON_DRAW,



		PLAY_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};


	GUI_MODE InterfaceMode;

	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuIconWidth;		//Width of each icon in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed



	window* pWind;

public:

	GUI();

	// Input Functions  ---------------------------
	void GetPointClicked(int& x, int& y) const;//Get coordinate where user clicks
	 window* DetectMouse();
	string GetSrting() const;	 //Returns a string entered by the user
	operationType GetUseroperation() const; //Read the user click and map to an operation

	// Output Functions  ---------------------------
	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar();	//creates Draw mode toolbar & menu
	void CreatePlayToolBar();	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	void setDrawColor(color);
	void setFillcolor(color);
	void ClearToolBar() const; // Function to clear toolbar

	// -- shapes Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const;  //Draw a rectangle
	void DrawTrian(Point P1, Point P2, Point P3, GfxInfo TrianGfxInfo)const;
	void DrawLi(Point P1, Point P2, GfxInfo LineGfxInfo) const;
	void DrawCircle(Point P1, double radius, GfxInfo LineGfxInfo) const;
	void DrawSq(Point P1, Point P2, GfxInfo RectGfxInfo) const;
	void DrawPoly(int* xArr,int* yArr, int numVertices, GfxInfo PolyGfxInfo) const;  //Draw Polygon
	void StickImage(string image, int x1, int y1, int x2, int y2);
	void DrawColorPalette();

	color GetColorPalette(const int x, const int y);
	void PickColor(int, int, double&, double&, double&);
	void waitKeyPress(char& cKey) const; // get keyboard clicks


	void PrintMessage(string msg) const;	//Print a message on Status bar
	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width


	~GUI();
};

