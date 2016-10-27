/*
 * =====================================================================================
 *
 *       Filename:  book_mark.h
 *
 *    Description:  book mark, can jump to the specific pos of the book
 *
 *        Created:  2016/10/27 20时05分01秒
 *       Compiler:  clang
 *
 *         Author:  TerenceWei 
 *          EMAIL:  360326661@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#pragma once

#include <string>
#include <memory>
#include "TypeDefine.h"
#include "orm_proxy.h"

enum
{
    BookMark_Desc_Len = 20,
};

enum BookMarkType
{
    BookMarkType_LastRead,
};

/*
 * =====================================================================================
 *        Class:  BookMark
 *  Description:  
 * =====================================================================================
 */
class BookMark : public OrmProxy
{
public:
    /* ====================  LIFECYCLE     ======================================= */
    BookMark ()
    {
        _desc.resize(BookMark_Desc_Len);
    }

    bool JumpToTheMark();

    bool operator < (const BookMark &mark) const
    {
        return _createTime < mark._createTime;
    }

    virtual void DBFieldRegister();

private:
    GETTER_SETTER(std::string, _bookPath);

    GETTER_SETTER_DEF(UInt32, _markPos, 0); // buffer pos

    GETTER_SETTER(std::string, _desc); // some description

    GETTER_SETTER_DEF(UInt32, _createTime, 0);
}; /* -----  end of class BookMark  ----- */

typedef std::shared_ptr<BookMark> BookMarkSptr;
