/*
 * =====================================================================================
 *
 *       Filename:  book.h
 *
 *    Description:  braille book
 *
 *        Created:  2016/10/27 20时21分19秒
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
#include "book_mark.h"

enum BookStatus
{
    BookStatus_Off, // 关闭状态
    BookStatus_On, // 打开状态
};

/*
 * =====================================================================================
 *        Class:  Book
 *  Description:  braille book, it shows the message through square points
 * =====================================================================================
 */
class Book
{
public:
    Book ();

    // 添加书签
    bool AddBookMark(BookMarkSptr sptr);

    // 删除书签
    void DelBookMark(UInt64 id);

    // 打开书
    void OpenBook();
    // 关闭书
    void CloseBook();

    BookMarkSptr FindBookMark(UInt64 id);
protected:

private:
    GETTER_SETTER(std::string, _bookTitle); // 标题
    GETTER_SETTER_DEF(UInt32, _curPos, 0); // current pos
    GETTER_SETTER(std::string, _bookPath); // 所在的路径
    GETTER_SETTER_DEF(UInt8, _status, 0); // 图书状态BookStatus

    BookMarkSptr _lastMark; // 上次阅读记录
    std::map<UInt64, BookMarkSptr> _marks;

    GETTER_SETTER(std::vector<UInt8>, _txt); // 书本信息

}; /* -----  end of class Book  ----- */

