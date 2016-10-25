#include "sqllite_db.h"

bool SqlliteClean(sqlite3 *db)
{
    sqlite3_close(db);  
    return true;
}

bool SqlliteDB::Init(const std::string &dbPath)
{
    sqlite3 *pDB = nullptr;
    int nRes = sqlite3_open(dbPath.c_str(),  &pDB);  

    if (nRes != SQLITE_OK)  {  
        cout<<"Open database fail: "<<sqlite3_errmsg(pDB);  
        return false;
    }  

    _dbSptr.reset(pDB, SqlliteClean);

    return true;
}

bool SqlliteDB::AddUser(const std::string& sName,  const std::string& sAge)  
{  
    std::string strSql = "";  
    strSql += "insert into user(name, age)";  
    strSql += "values('";  
    strSql += sName;  
    strSql += "', ";  
    strSql += sAge;  
    strSql += ");";  

    char* cErrMsg;  
    int nRes = sqlite3_exec(_dbSptr.get() ,  strSql.c_str() , 0 , 0,  &cErrMsg);  
    if (nRes != SQLITE_OK)    {  
        cout<<"add user fail: "<<cErrMsg<<endl;
        return false;  
    }  
    else {
        cout<<"add user success: "<<sName.c_str()<<"\t"<<sAge.c_str()<<endl;  
    }

    return true;
}  

bool SqlliteDB::DeleteUser(const std::string& sName)  
{  
    std::string strSql = "";  
    strSql += "delete from user where name='";
    strSql += sName;
    strSql += "';";  

    char* cErrMsg;
    int nRes = sqlite3_exec(_dbSptr.get() ,  strSql.c_str() , 0 , 0,  &cErrMsg);  
    if (nRes != SQLITE_OK)    {  
        cout<<"delete user fail: "<<cErrMsg<<endl;  
        return false;  
    }  
    else  {  
        cout<<"delete user success: "<<sName.c_str()<<endl;  
    }  

    return true;  
}  

bool SqlliteDB::ModifyUser(const std::string& sName,  const std::string& sAge)  
{  
    std::string strSql = "";  
    strSql += "update user set age =";  
    strSql += sAge;  
    strSql += " where name='";  
    strSql += sName;  strSql += "';";  

    char* cErrMsg;  
    int nRes = sqlite3_exec(_dbSptr.get() ,  strSql.c_str() , 0 , 0,  &cErrMsg);  
    if (nRes != SQLITE_OK)    {  
        cout<<"modify user fail: "<<cErrMsg<<endl;  
        return false;  
    }  
    else  {  
        cout<<"modify user success: "<<sName.c_str()<<"\t"<<sAge.c_str()<<endl;  
    }  

    return true;  
}  

bool SqlliteDB::SelectUser()  
{  
    char* cErrMsg;  
    int res = sqlite3_exec(_dbSptr.get(),  "select * from user;",  UserResult,  0 ,  &cErrMsg);    
    if (res != SQLITE_OK)  {  
        return false;  
    }  
    return true;  
}
