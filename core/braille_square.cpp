#include "braille_square.h"

bool BrailleSquare::IsInside(const Pos &pos)
{
    if (pos.x >= _pos.x && pos.x <= _pos.x + SQUARE_LENGTH_FIXEL &&
        pos.y >= _pos.y && pos.y <= _pos.y + SQUARE_WIDTH_FIXEL) {
        return true;
    }

    return false;
}
