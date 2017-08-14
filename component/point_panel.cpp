#include "point_panel.h"

PointPanel::PointPanel ()
{
    for (UInt32 x = 0; x < ROW_POINT_NUM; ++x) {
        for (UInt32 y = 0; y < COLUMN_POINT_NUM; ++y) {
            Int32 index = GetIndex(x,  y);

            _pointArr[index].panelPos.x = x;
            _pointArr[index].panelPos.y = y;
        }
    }
}

UInt32 PointPanel::GetIndex(UInt32 x,  UInt32 y)
{
    if (x >= ROW_POINT_NUM ||
        y >= COLUMN_POINT_NUM) {
        return -1;
    }

    return x * COLUMN_POINT_NUM + y;
}

void PointPanel::Activate(UInt32 x,  UInt32 y)
{
    Int32 index = GetIndex(x,  y);
    if (index < 0) {
        return;
    }
    _pointArr[index].status = PointStatus_Active;
}

void PointPanel::Unactivate(UInt32 x,  UInt32 y)
{
    Int32 index = GetIndex(x,  y);
    if (index < 0) {
        return;
    }
    _pointArr[index].status = PointStatus_Inactive;
}

void PointPanel::UnactivateAll()
{
    for (UInt32 x = 0; x < ROW_POINT_NUM; ++x) {
        for (UInt32 y = 0; y < COLUMN_POINT_NUM; ++y) {

            Int32 index = GetIndex(x,  y);
            _pointArr[index].status = PointStatus_Inactive;
        }
    }
}
