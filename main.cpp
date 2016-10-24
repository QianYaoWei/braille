#include <iostream>
#include "braille_screen.h"

using namespace std;

int main()
{
    Pos pos;
    BrailleScreen::Instance()->OnTouch(pos);
    return 0;
}				/* ----------  end of function main  ---------- */
