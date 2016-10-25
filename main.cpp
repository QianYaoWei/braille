#include <iostream>
#include "braille_screen.h"
#include "py_stript_interface.h"

using namespace std;

int main()
{
    Pos pos;
    BrailleScreen::Instance()->OnTouch(pos);
    PyScriptInterface::Instance()->Init("braille_translator");
    return 0;
}				/* ----------  end of function main  ---------- */
