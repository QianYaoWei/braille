#pragma once
#include "braille_square.h"

enum PageTurningType
{
    PageTurningType_Invalid = 0,
    PageTurningType_Up = 1,     // 上翻页
    PageTurningType_Down = 2,   // 下翻页
};

/*
 * =====================================================================================
 *        Class:  PageTurningButton
 *  Description:  
 * =====================================================================================
 */
class PageTurningButton : public BrailleSquare
{
public:
    /* ====================  LIFECYCLE     ======================================= */
    PageTurningButton ();                             /* constructor */

    // 按下
    virtual void OnDown();

    // 按下抬起
    virtual void OnDownUp();

    // 抬起
    virtual void OnUp();

    // 抬起按下
    virtual void OnUpDown();

protected:
    PageTurningType _type {};
}; /* -----  end of class PageTurningButton  ----- */
