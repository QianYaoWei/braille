/*
 * =====================================================================================
 *
 *       Filename:  point_panel.h
 *
 *    Description: 
 *
 *        Created:  03/09/17 16:04:18
 *       Compiler:  clang
 *
 *         Author:  TerenceWei 
 *          EMAIL:  360326661@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#pragma once
#include "Pos.h"
#include "Singleton.h"

enum
{
    ROW_POINT_NUM = 30, // 横向点数
    COLUMN_POINT_NUM = 12, // 纵向点数
};

enum PointStatus
{
    PointStatus_Inactive, // 未激活状态
    PointStatus_Active, // 激活状态
};

struct Point
{
    // 所在屏幕坐标
    // Pos screenPos;
    // 所在逻辑面板坐标
    Pos panelPos;
    // 状态
    PointStatus status {PointStatus_Inactive};
};

// ------y ROW_POINT_NUM
// |
// |
// x
// COLUMN_POINT_NUM

/*
 * =====================================================================================
 *        Class:  PointPanel
 *  Description:  该类与硬件交互，通过点的状态控制硬件上的点
 * =====================================================================================
 */
class PointPanel
{
    public:
        /* ====================  LIFECYCLE     ======================================= */
        PointPanel ();                             /* constructor      */

        Int32 GetIndex(UInt32 x,  UInt32 y);

        // 激活该点
        void Activate(UInt32 x,  UInt32 y);

        // 反激活该点
        void Unactivate(UInt32 x,  UInt32 y);

        void UnactivateAll();

        void DrawPoints();

    protected:

    private:
        Point _pointArr[ROW_POINT_NUM * COLUMN_POINT_NUM];
}; /* -----  end of class PointPanel  ----- */

