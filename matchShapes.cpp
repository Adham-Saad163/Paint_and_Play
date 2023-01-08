//#include "matchShapes.h"
//#include "controller.h"
//#include "GUI/GUI.h"
//#include <iostream>
//
//matchShapes::matchShapes(controller* pCont) :operation(pCont)
//{}
//matchShapes::~matchShapes()
//{}
//
////Execute the operation
//void matchShapes::Execute()
//{
//	GUI* pUI = pControl->GetUI();
//	Graph* pGr = pControl->getGraph();
//
//	// First for selecting:
//	Point P;
//	pUI->getMouseCoord(P.x, P.y);
//
//	if (pGr->Getshape(P.x, P.y))
//	{
//		pGr->unSeletAll(); 							//unselect everything
//		pGr->Getshape(P.x, P.y)->SetSelected(true);		//make this shape is selected
//		pGr->addSelectedShape(pGr->Getshape(P.x, P.y));
//	}
//	else
//	{
//		pGr->unSeletAll();
//		pUI->ClearStatusBar();
//	}
//
//	// For matching:
//
//	if (pGr->getMatchedShapes().size() == 0)
//	{
//		if (pGr->getSelectedShape())
//		{
//			shape* firstSelectedShape = pGr->getSelectedShape();
//			//put the unhide functin here for the first selectedShape
//			pGr->addMatchedShape(firstSelectedShape);
//		}
//		pGr->unSeletAll();
//	}
//	else if (pGr->getMatchedShapes().size() == 1)
//	{
//		if (pGr->getSelectedShape() && (pGr->getSelectedShape() != pGr->getMatchedShapes()[0]))
//		{
//			shape* secondSelectedShape = pGr->getSelectedShape();
//			//put the unhide functin here for the second selectedShape
//			pGr->addMatchedShape(secondSelectedShape);
//			pGr->unSeletAll();
//
//			// if the IDs of the two shapes is the same, delete them
//
//			
//			if (pGr->getMatchedShapes()[0]->getDuplicateID() == pGr->getMatchedShapes()[1]->getDuplicateID())
//			{
//				pGr->DeleteShape(pGr->getMatchedShapes()[0]); pGr->DeleteShape(pGr->getMatchedShapes()[1]); // deletes both shapes after 
//																											// finding a match
//				pGr->clearMatchedShapes();  // clears the vector after finding a match
//			}
//			else
//			{
//				// Hide the two shapes again
//				pGr->clearMatchedShapes();
//			}
//		}
//		pGr->unSeletAll();
//
//	}
//}
//
//void matchShapes::Undo() {}
//void matchShapes::Redo() {}