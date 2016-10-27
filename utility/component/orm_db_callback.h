/*
 * =====================================================================================
 *
 *       Filename:  orm_db_callback.h
 *
 *    Description:  decode data after db operation
 *
 *        Created:  2016/10/26 16时28分02秒
 *       Compiler:  clang
 *
 *         Author:  TerenceWei 
 *          EMAIL:  360326661@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#pragma once
#include <list>
#include <memory>

enum CallBackType
{
    CallBackType_Normal = 1,
    CallBackType_Select = 2,

    // CallBackType_Insert = 3,
    // CallBackType_Update = 4,
    // CallBackType_Del = 5
};

/*
 * =====================================================================================
 *        Class:  OrmDBCallBack
 *  Description:  
 * =====================================================================================
 */
class OrmDBCallBack
{
public:
    OrmDBCallBack ()
    {
    }

    virtual ~OrmDBCallBack ()
    {
    }

    virtual void OnFailed() {}

    virtual CallBackType GetType()
    {
        return CallBackType_Normal;
    }
protected:

private:
}; /* -----  end of class OrmDBCallBack  ----- */


/*
 * =====================================================================================
 *        Class:  SelectOrmDBCallBackBase
 *  Description:  
 * =====================================================================================
 */
class SelectOrmDBCallBackBase : public OrmDBCallBack
{
public:
    SelectOrmDBCallBackBase ()
    {
    }

    virtual ~SelectOrmDBCallBackBase()
    {
    }

    virtual int SelectResult(void *user,  int argc,  char **argv,  char **azColName) = 0;

    virtual CallBackType GetType()
    {
        return CallBackType_Select;
    }
protected:

private:
}; /* -----  end of class SelectOrmDBCallBackBase  ----- */


template<class T>
class SelectOrmDBCallBack : public SelectOrmDBCallBackBase
{
public:
    typedef std::shared_ptr<T> TSptr;

    TSptr GetNext()
    {
        if (_tlist.empty()) {
            return nullptr;
        }

        auto pt = _tlist.back();
        _tlist.pop_back();

        return pt;
    }

    bool Empty() { return _tlist.empty(); }

    int SelectResult(void *user,  int argc,  char **argv,  char **azColName)  
    {
        auto sptr = std::make_shared<T>();
        sptr->DBFieldRegister();
        _tlist.push_back(sptr);

        for (int i = 0; i < argc; ++i) {
            if (azColName[i] != nullptr && argv[i] != nullptr) {
                sptr->AssignField(azColName[i], argv[i]);
            }
        } 

        return 0;
    }

private:
    std::list<TSptr> _tlist;
}; /* -----  end of class SelectOrmDBCallBack  ----- */


template<class T>
class SelectOrmDBCallBackPt : public SelectOrmDBCallBackBase
{
public:
    T *GetNext()
    {
        if (_tlist.empty()) {
            return nullptr;
        }

        auto pt = _tlist.back();
        _tlist.pop_back();

        return pt;
    }

    bool Empty() { return _tlist.empty(); }

    int SelectResult(void *user,  int argc,  char **argv,  char **azColName)  
    {
        auto pt = new T;
        pt->DBFieldRegister();
        _tlist.push_back(pt);

        for (int i = 0; i < argc; ++i) {
            if (azColName[i] != nullptr && argv[i] != nullptr) {
                pt->AssignField(azColName[i], argv[i]);
            }
        } 
    }

private:
    std::list<T *> _tlist;
}; /* -----  end of class SelectOrmDBCallBack  ----- */
