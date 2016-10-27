#include "sqlite_db.h"
#include "stringutil.h"
#include "orm_db_callback.h"

using namespace utility;

int DBCallbackFunc(void *user,  int argc,  char **argv,  char **azColName)
{
    if (nullptr == user) {
        return 1;
    }

    OrmDBCallBack *callback = reinterpret_cast<OrmDBCallBack *>(user);

    if (callback->GetType() == CallBackType_Select) {
        SelectOrmDBCallBackBase *callbackBase = dynamic_cast<SelectOrmDBCallBackBase *>(callback);
        if (callbackBase != nullptr) {
            callbackBase->SelectResult(user, argc, argv, azColName);
        }
    }

    return 0;
};


bool SqliteClean(sqlite3 *db)
{
    sqlite3_close(db);  
    return true;
}

bool SqliteDB::Init(const std::string &dbPath)
{
    sqlite3 *pDB = nullptr;
    int nRes = sqlite3_open(dbPath.c_str(),  &pDB);  

    if (nRes != SQLITE_OK)  {  
        std::cout<<"Open database fail: "<<sqlite3_errmsg(pDB);  
        return false;
    }  

    _dbSptr.reset(pDB, SqliteClean);

    return true;
}

bool SqliteDB::LoadInitSql(const std::string &iniSql)
{
    return true;
}

bool SqliteDB::ExecuteSql(const std::string &sql, OrmDBCallBack *callback)
{
    char* cErrMsg;  
    int nRes = sqlite3_exec(_dbSptr.get(), sql.c_str(), DBCallbackFunc, callback, &cErrMsg);  

    if (nRes != SQLITE_OK)    {  
        std::cout<<"execute sql failed: "<< cErrMsg <<std::endl;  
        return false;  
    }  
    else  {  
        std::cout<<"execute sql Done!" << std::endl;
        return true;  
    }  
}

bool SqliteDB::ExecuteSqlEx(OrmDBCallBack *callback)
{
    char* cErrMsg;  
    int nRes = sqlite3_exec(_dbSptr.get(), s_arrSql.get(), DBCallbackFunc, callback, &cErrMsg);  

    if (nRes != SQLITE_OK)    {  
        std::cout<<"execute sql failed: "<< cErrMsg <<std::endl;  
        return false;  
    }  
    else  {  
        std::cout<<"execute sql Done!" << std::endl;
        return true;  
    }  

    return true;
}
