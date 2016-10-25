#include "page_turning_button.h"

void PageTurningButton::OnDown()
{
    BrailleSquare::OnDown();
}

// 按下抬起
void PageTurningButton::OnDownUp()
{
    BrailleSquare::OnDownUp();
}

// 抬起
void PageTurningButton::OnUp()
{
    BrailleSquare::OnUp();
}

// 抬起按下
void PageTurningButton::OnUpDown()
{
    BrailleSquare::OnUpDown();

    switch ( _type ) {
        case PageTurningType_Up:	
            break;

        case PageTurningType_Down:	
            break;

        default:	
            break;
    }				/* -----  end switch  ----- */
}
