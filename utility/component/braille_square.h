/*
 * =====================================================================================
 *
 *       Filename:  braille_square.h
 *
 *    Description:  braille square consists of 6 points, every 
 *                  point has its own two status on or off
 *
 *        Created:  2016/10/26 16时03分48秒
 *       Compiler:  clang
 *
 *         Author:  TerenceWei 
 *          EMAIL:  360326661@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#pragma once
#include <vector>
#include <memory>
#include "Pos.h"
#include "TypeDefine.h"

enum BraillePoint
{
    BraillePoint_1 = 0x01,
    BraillePoint_2 = 0x02,
    BraillePoint_3 = 0x04,
    BraillePoint_4 = 0x08,
    BraillePoint_5 = 0x10,
    BraillePoint_6 = 0x20,

    BraillePoint_7 = 0x40,
    BraillePoint_8 = 0x80,
};

enum
{
    BrailleSquare_Valid = BraillePoint_7, // 该方块是否有效

    BrailleSquare_Active = BraillePoint_8, // 该方块是否激活 
};

enum
{
    // 屏幕长度
    SCREEN_LENGTH_FIXEL = 1000,
    // 屏幕宽度
    SCREEN_WIDTH_FIXEL = 500,

    // 方块长度
    SQUARE_LENGTH_FIXEL = 20,
    // 方块宽度
    SQUARE_WIDTH_FIXEL = 30,

    // 方块间横向间距
    // SQUARE_LENGTH_DISTANCE_FIXEL = 5,
    // 方块间纵向间距
    // SQUARE_WIDTH_DISTANCE_FIXEL = 8,

    // 方块与屏幕之间的横向间距
    // SQUARE_SCREEN_LENGTH_DISTANCE_FIXEL = 10,
    // 方块与屏幕之间的纵向间距
    // SQUARE_SCREEN_WIDTH_DISTANCE_FIXEL = 10,
};

class BrailleSquare;
typedef std::shared_ptr<BrailleSquare> BrailleSquareSptr;

class BrailleSquare
{
public:
    bool IsPointSet(BraillePoint p) const { return _points & p; }

    // 方块是否有效
    bool IsValid() const { return _points & BrailleSquare_Valid; }

    // 方块是否被激活
    bool IsActive() const { return _points & BrailleSquare_Active; }
    // 激活方块
    void Activate() { _points &= BrailleSquare_Active; }
    // 去掉激活状态
    void Inactivate() { _points &= ~(BrailleSquare_Active); }

    unsigned char GetPoint() const { return _points; }
    void SetPoint(unsigned char point) { _points = point; }
    void ResetPoint() { SetPoint(0); };

    // 按下
    virtual void OnDown()
    {
        Activate();
    }

    // 按下抬起
    virtual void OnDownUp()
    {
        Inactivate();
    }

    // 抬起
    virtual void OnUp()
    {
        Inactivate();
    }

    // 抬起按下
    virtual void OnUpDown()
    {
        Activate();
    }

    virtual void OnMoveFromLeft(BrailleSquareSptr sptr) {}
    virtual void OnMoveToLeft(BrailleSquareSptr sptr) {}

    virtual void OnMoveFromRight(BrailleSquareSptr sptr) {}
    virtual void OnMoveToRight(BrailleSquareSptr sptr) {}

    virtual void OnMoveFromUp(BrailleSquareSptr sptr) {}
    virtual void OnMoveToUp(BrailleSquareSptr sptr) {}

    virtual void OnMoveFromDown(BrailleSquareSptr sptr) {}
    virtual void OnMoveToDown(BrailleSquareSptr sptr) {}

    // 单击
    // virtual void OnOneClick() {}
    // 双击
    // virtual void OnDoubleClick() {}

    Pos GetPos() { return _pos; }
    void SetPos(const Pos &pos) { _pos = pos; }

    // 坐标是否处于方块内
    bool IsInside(const Pos &pos);

protected:
    unsigned char _points {BrailleSquare_Valid};
    Pos _pos; // 方块左上角所在屏幕坐标
};

typedef std::vector<BraillePoint> BraillePointVec;
typedef std::vector<BrailleSquareSptr> BraillePointSptrVec;
