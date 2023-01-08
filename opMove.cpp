#include "opMove.h"
#include "controller.h"
#include "GUI/GUI.h"

opMove::opMove(controller* pCont) :operation(pCont)
{}
opMove::~opMove()
{}

//Execute the operation
void opMove::Execute()
{
    
    GUI* pUI = pControl->GetUI();
    Point P1, P2;
    pUI->PrintMessage("Choose a shape to move ");
    pUI->GetPointClicked(P1.x, P1.y);
    pUI->ClearStatusBar();
    Graph* pGr = pControl->getGraph();
    if (pGr->Getshape(P1.x, P1.y) != nullptr)
    {
        pUI->PrintMessage("Start move The Shape ");
        pUI->GetPointClicked(P2.x, P2.y);
        pUI->ClearStatusBar();
        shape* Selected_shape = pGr->Getshape(P1.x, P1.y);
        Selected_shape->Move(P2);
    }
}



void opMove::Undo()
{
    Graph* pGr = pControl->getGraph();
    pGr->SendFromShapesListToUndo();
}
void opMove::Redo()
{
    Graph* pGr = pControl->getGraph();
    pGr->SendFromUndoToShapesList();
}




  

/*Point P;
    GUI* pUI = pControl->GetUI();
    Graph* pGr = pControl->getGraph();
    window* pWind = pUI->DetectMouse();
    if (pGr->Selectd)
    {
        pUI->PrintMessage(" move ");
        shape* Selected_shape = pGr->getSelectedShape();
        while (pWind->GetButtonState(LEFT_BUTTON, P.x, P.y) != BUTTON_DOWN)
        {
  
            Selected_shape->Move(P);
        }
            
    }
*/