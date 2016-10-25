#pragma once
#include <string>

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

protected:
    std::string _filePath;
    unsigned int _markPos {0};
    std::string _desc; // some description
    unsigned int _createTime {0};
private:
}; /* -----  end of class BookMark  ----- */
