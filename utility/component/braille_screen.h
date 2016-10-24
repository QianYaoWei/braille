#pragma once

#include "braille_square.h"
#include "Singleton.h"
#include "Pos.h"

// 方块类型
enum SquareType
{
    SquareType_Norm = 1,
    SquareType_Func,
    SquareType_All,
};

/*
 * =====================================================================================
 *        Class:  BrailleScreen
 *  Description:  
 * =====================================================================================
 */
class BrailleScreen : public utility::Singleton<BrailleScreen>
{
public:
    // 触摸屏幕
    void OnTouch(const Pos &pos);
    // 手指离开屏幕
    void OnUpScreen();

    // 通过坐标获取方块
    BrailleSquareSptr GetSqure(const Pos &pos);

    // 通过像素参数计算出方块数量
    // unsigned short GetSquareNum()
    // {
    //     return 0;
    // }

    // 按下
    void Down(const Pos &pos);

    // 按下抬起
    void DownUp(const Pos &pos);

    // 抬起
    void Up(const Pos &pos);

    // 抬起按下
    void UpDown(const Pos &pos);

    // 重置方块
    void ResetSquares(SquareType type);

    // 清掉方块
    void ClearSquares(SquareType type);

    // 添加方块
    void AddSquare(const Pos &pos, SquareType type);
private:
    // 普通方块
    BraillePointSptrVec _normSquares;
    // 功能性方块
    BraillePointSptrVec _funcSquares;

    // 所有方块
    BraillePointSptrVec _allSquares;
}; /* -----  end of class BrailleScreen  ----- */

