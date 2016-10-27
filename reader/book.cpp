#include "book.h"

bool Book::AddBookMark(BookMarkSptr sptr)
{
    UInt64 id = sptr->GetID();
    if (FindBookMark(id)) {
        // 已经存在相同ID的
        return false;
    }

    id = sptr->GetID();
    _marks[id] = sptr;

    sptr->Set_markPos(_curPos); // 记录下当前阅读进度
    // sptr->Set_desc(); // 记录该进度部分内容
    
    // sptr->SyncDataToDB();
    return true;
}

// 删除书签
void Book::DelBookMark(UInt64 id)
{
    auto itr = _marks.find(id);
    if (itr != _marks.end()) {
        itr->second->DelFromDB("book_marks");
        _marks.erase(itr);
    }
}

// 打开书
void Book::OpenBook()
{
    // TODO

}

// 关闭书
void Book::CloseBook()
{
    // TODO

}

BookMarkSptr Book::FindBookMark(UInt64 id)
{
    auto itr = _marks.find(id);
    if (itr != _marks.end()) {
        return itr->second;
    }

    return nullptr;
}
