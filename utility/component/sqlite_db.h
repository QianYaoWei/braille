/*
 * =====================================================================================
 *
 *       Filename:  sqlite_db.h
 *
 *    Description:  sqlite access manager
 *
 *        Created:  2016/10/26 16时06分24秒
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
#include <map>
#include <memory>
#include <iostream>
#include <sqlite3.h>
#include "AnyType.h"
#include "Singleton.h"

typedef std::shared_ptr<sqlite3> sqlite3Sptr;

class OrmDBCallBack;
/*
 * =====================================================================================
 *        Class:  SqliteDB
 *  Description:  
 * =====================================================================================
 */
class SqliteDB : public utility::Singleton<SqliteDB>
{
    friend class OrmProxy;
public:
    enum
    {
        SQL_LEN = 512,
    };

    SqliteDB () : s_arrSql(new(std::nothrow) char[SQL_LEN])
    {
    }

    bool Init(const std::string &dbPath);

    bool ExecuteSql(const std::string &sql, OrmDBCallBack *callback);

    bool ExecuteSqlEx(OrmDBCallBack *callback);
private:
    bool LoadInitSql(const std::string &iniSql);

    char *GetSqlArray() { return s_arrSql.get(); }

    sqlite3Sptr _dbSptr;

    std::unique_ptr<char []> s_arrSql;
}; /* -----  end of class SqliteDB  ----- */

bool SqliteClean(sqlite3 *db);
