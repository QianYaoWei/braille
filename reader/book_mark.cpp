#include "book_mark.h"

bool BookMark::JumpToTheMark()
{
    return true;
}

void BookMark::DBFieldRegister()
{
    ObjAndDBMapping("bookpath", _bookPath);
    ObjAndDBMapping("mark_pos", _markPos);
    ObjAndDBMapping("descri", _desc);
    ObjAndDBMapping("create_time", _createTime);
}
