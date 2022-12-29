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
