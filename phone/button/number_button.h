#pragma once
#include "braille_square.h"

/*
 * =====================================================================================
 *        Class:  NumberButton
 *  Description:  
 * =====================================================================================
 */
class NumberButton : public BrailleSquare
{
public:
    /* ====================  LIFECYCLE     ======================================= */
    NumberButton (unsigned char num) : _num(num)
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
    // 数字键
    unsigned char _num {0};
}; /* -----  end of class NumberButton  ----- */

