#include <iostream>
#include "braille_screen.h"
#include "py_stript_interface.h"
#include "sqllite_db.h"

using namespace std;

int main()
{
    Pos pos;
    BrailleScreen::Instance()->OnTouch(pos);
    PyScriptInterface::Instance()->Init("braille_translator");
    SqlliteDB::Instance()->Init("/tmp/aa");
    return 0;
}				/* ----------  end of function main  ---------- */
