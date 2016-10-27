#include <iostream>
#include "braille_screen.h"
#include "py_stript_interface.h"
#include "sqlite_db.h"
#include "id_generator_mgr.h"

using namespace std;

int main()
{
    Pos pos;
    BrailleScreen::Instance()->OnTouch(pos);

    PyScriptInterface::Instance()->Init("/Users/terencewei/my_src/braille/script/python/", "braille_translator");

    std::vector<UInt16> retVec;
    PyScriptInterface::Instance()->TranslateFile("/Users/terencewei/gitsrc/python-pinyin/file", retVec);
    
    for (auto &elem : retVec) {
        cout<<elem<<endl;
    }

    SqliteDB::Instance()->Init("/Users/terencewei/my_src/braille/build/braille_db");

    IDGeneratorMgr::Instance()->Init();
    return 0;
}				/* ----------  end of function main  ---------- */
