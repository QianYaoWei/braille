#pragma once

#include <sqlite3.h>
#include <string>
#include <memory>
#include <iostream>
#include "Singleton.h"

using namespace std;

typedef std::shared_ptr<sqlite3> sqlite3Sptr;

/*
 * =====================================================================================
 *        Class:  SqlliteDB
 *  Description:  
 * =====================================================================================
 */
class SqlliteDB : public utility::Singleton<SqlliteDB>
{
public:
    /* ====================  LIFECYCLE     ======================================= */
    SqlliteDB ()
    {
    }

    bool Init(const std::string &dbPath);

    //增加用户  
    bool AddUser(const std::string& sName,  const std::string& sAge);  
    ////删除用户  
    bool DeleteUser(const std::string& sName);  
    ////修改用户  
    bool ModifyUser(const std::string& sName,  const std::string& sAge);  
    //查找用户  
    bool SelectUser();  

    static int UserResult(void *NotUsed,  int argc,  char **argv,  char **azColName)  
    {  
        for(int i = 0 ; i < argc ; i++)  {  
            cout<<azColName[i]<<" = "<<(argv[i] ? argv[i] : "NULL")<<",  ";  
        }  
        cout<<endl;  
        return 0;  
    }  

private:

    sqlite3Sptr _dbSptr;
}; /* -----  end of class SqlliteDB  ----- */

bool SqlliteClean(sqlite3 *db);


// int _tmain(int argc,  _TCHAR* argv[])  
// {
//     //打开路径采用utf-8编码  
//     //如果路径中包含中文，需要进行编码转换  
//     int nRes = sqlite3_open("D:\\sqlite\\test.db",  &pDB);  
//     if (nRes != SQLITE_OK)  {  
//         cout<<"Open database fail: "<<sqlite3_errmsg(pDB);  
//         goto QUIT;  
//     }  
// 
//     //添加“赵钱孙李”  
//     if (    !AddUser("zhao",  "18")  || !AddUser("qian",  "19")  || !AddUser("sun",  "20")  || !AddUser("li",  "21"))  {  
//         goto QUIT;  
//     }  
// 
//     //删除“赵”  
//     if (!DeleteUser("zhao"))  {  
//         goto QUIT;  
//     }  
// 
//     //修改“孙”  
//     if (!ModifyUser("sun",  "15"))  {  
//         goto QUIT;  
//     }  
// 
//     //查找用户  
//     if (!SelectUser())  {  
//         goto QUIT;  
//     }  
// 
//     sqlite3_close(pDB);  
//     return 0;  
// }
