#pragma once
#include "braille_square.h"

/*
 * =====================================================================================
 *        Class:  DialButton
 *  Description:  
 * =====================================================================================
 */
class DialButton : public BrailleSquare
{
public:
    /* ====================  LIFECYCLE     ======================================= */
    DialButton ()
    {
    }

    // 按下
    virtual void OnDown();

    // 按下抬起
    virtual void OnDownUp();

    // 抬起
    virtual void OnUp();

    // 抬起按下
    virtual void OnUpDown();

protected:

}; /* -----  end of class DialButton  ----- */


