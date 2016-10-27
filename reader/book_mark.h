#pragma once

#include <string>
#include <memory>

enum
{
    BookMark_Desc_Len = 20,
};

/*
 * =====================================================================================
 *        Class:  BookMark
 *  Description:  
 * =====================================================================================
 */
class BookMark
{
public:
    /* ====================  LIFECYCLE     ======================================= */
    BookMark ()
    {
    }

    bool JumpToTheMark();

    bool operator < (const BookMark &mark) const
    {
        return _createTime < mark._createTime;
    }

protected:
    std::string _filePath;

    unsigned int _markPos {0}; // buffer pos

    std::string _desc; // some description

    unsigned int _createTime {0};
}; /* -----  end of class BookMark  ----- */

typedef std::shared_ptr<BookMark> BookMarkSptr;
