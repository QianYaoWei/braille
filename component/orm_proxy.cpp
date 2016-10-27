#include "orm_proxy.h"
#include "sqlite_db.h"
#include "AnyType.h"
#include "stringutil.h"

using namespace utility;

bool OrmProxy::SelectFromDB(const std::string &_strTable, OrmDBCallBack *callback)
{
    char *sqlArr = SqliteDB::Instance()->GetSqlArray();
    snprintf(sqlArr, SqliteDB::SQL_LEN, "SELECT * FROM %s;", _strTable.c_str());
    return SqliteDB::Instance()->ExecuteSqlEx(callback);
}

bool OrmProxy::SyncDataToDB(const std::string &_strTable, OrmDBCallBack *callback)
{
    char *sqlArr = SqliteDB::Instance()->GetSqlArray();
    size_t offset = snprintf(sqlArr, SqliteDB::SQL_LEN, "UPDATE %s SET ", _strTable.c_str());
    
    size_t i = 0;
    for ( auto &elem : _objFieldType ) {
        switch ( elem.second ) {
            case AnyType_String:	
                {
                    std::string &strData = *reinterpret_cast<std::string *>(_objFieldPt[elem.first]);
                    if ( i == _objFieldType.size() - 1) {
                        // the last element
                        offset += snprintf(sqlArr + offset, SqliteDB::SQL_LEN - offset, "%s=\"%s\" ", elem.first.c_str(), strData.c_str());
                    }
                    else {
                        offset += snprintf(sqlArr + offset, SqliteDB::SQL_LEN - offset, "%s=\"%s\",", elem.first.c_str(), strData.c_str());
                    }

                    break;
                }
            case AnyType_Int8:
                {
                    Int8 &val = *reinterpret_cast<Int8 *>(_objFieldPt[elem.first]);
                    if ( i == _objFieldType.size() - 1) {
                        offset += snprintf(sqlArr + offset, SqliteDB::SQL_LEN - offset, "%s=%d ", elem.first.c_str(), val);
                    }
                    else {
                        offset += snprintf(sqlArr + offset, SqliteDB::SQL_LEN - offset, "%s=%d,", elem.first.c_str(), val);
                    }
                    break;
                }
            case AnyType_UInt8:
                {
                    UInt8 &val = *reinterpret_cast<UInt8 *>(_objFieldPt[elem.first]);
                    if ( i == _objFieldType.size() - 1) {
                        offset += snprintf(sqlArr + offset, SqliteDB::SQL_LEN - offset, "%s=%u ", elem.first.c_str(), val);
                    }
                    else {
                        offset += snprintf(sqlArr + offset, SqliteDB::SQL_LEN - offset, "%s=%u,", elem.first.c_str(), val);
                    }
                    break;
                }
            case AnyType_Int16:
                {
                    Int16 &val = *reinterpret_cast<Int16 *>(_objFieldPt[elem.first]);
                    if ( i == _objFieldType.size() - 1) {
                        offset += snprintf(sqlArr + offset, SqliteDB::SQL_LEN - offset, "%s=%d ", elem.first.c_str(), val);
                    }
                    else {
                        offset += snprintf(sqlArr + offset, SqliteDB::SQL_LEN - offset, "%s=%d,", elem.first.c_str(), val);
                    }
                    break;
                }
            case AnyType_UInt16:
                {
                    UInt16 &val = *reinterpret_cast<UInt16 *>(_objFieldPt[elem.first]);
                    if ( i == _objFieldType.size() - 1) {
                        offset += snprintf(sqlArr + offset, SqliteDB::SQL_LEN - offset, "%s=%u ", elem.first.c_str(), val);
                    }
                    else {
                        offset += snprintf(sqlArr + offset, SqliteDB::SQL_LEN - offset, "%s=%u,", elem.first.c_str(), val);
                    }
                    break;
                }
            case AnyType_Int32:
                {
                    Int32 &val = *reinterpret_cast<Int32 *>(_objFieldPt[elem.first]);
                    if ( i == _objFieldType.size() - 1) {
                        offset += snprintf(sqlArr + offset, SqliteDB::SQL_LEN - offset, "%s=%d ", elem.first.c_str(), val);
                    }
                    else {
                        offset += snprintf(sqlArr + offset, SqliteDB::SQL_LEN - offset, "%s=%d,", elem.first.c_str(), val);
                    }
                    break;
                }
            case AnyType_UInt32:
                {
                    UInt32 &val = *reinterpret_cast<UInt32 *>(_objFieldPt[elem.first]);
                    if ( i == _objFieldType.size() - 1) {
                        offset += snprintf(sqlArr + offset, SqliteDB::SQL_LEN - offset, "%s=%u ", elem.first.c_str(), val);
                    }
                    else {
                        offset += snprintf(sqlArr + offset, SqliteDB::SQL_LEN - offset, "%s=%u,", elem.first.c_str(), val);
                    }
                    break;
                }
            case AnyType_Int64:
                {
                    Int64 &val = *reinterpret_cast<Int64 *>(_objFieldPt[elem.first]);
                    if ( i == _objFieldType.size() - 1) {
                        offset += snprintf(sqlArr + offset, SqliteDB::SQL_LEN - offset, "%s=%lld ", elem.first.c_str(), val);
                    }
                    else {
                        offset += snprintf(sqlArr + offset, SqliteDB::SQL_LEN - offset, "%s=%lld,", elem.first.c_str(), val);
                    }
                    break;
                }
            case AnyType_UInt64:
                {
                    UInt64 &val = *reinterpret_cast<UInt64 *>(_objFieldPt[elem.first]);
                    if ( i == _objFieldType.size() - 1) {
                        offset += snprintf(sqlArr + offset, SqliteDB::SQL_LEN - offset, "%s=%llu ", elem.first.c_str(), val);
                    }
                    else {
                        offset += snprintf(sqlArr + offset, SqliteDB::SQL_LEN - offset, "%s=%llu,", elem.first.c_str(), val);
                    }
                    break;
                }
            case AnyType_Real32:
                {
                    Real32 &val = *reinterpret_cast<Real32 *>(_objFieldPt[elem.first]);
                    if ( i == _objFieldType.size() - 1) {
                        offset += snprintf(sqlArr + offset, SqliteDB::SQL_LEN - offset, "%s=%f ", elem.first.c_str(), val);
                    }
                    else {
                        offset += snprintf(sqlArr + offset, SqliteDB::SQL_LEN - offset, "%s=%f,", elem.first.c_str(), val);
                    }
                    break;
                }
            case AnyType_Real64:
                {
                    Real64 &val = *reinterpret_cast<Real64 *>(_objFieldPt[elem.first]);
                    if ( i == _objFieldType.size() - 1) {
                        offset += snprintf(sqlArr + offset, SqliteDB::SQL_LEN - offset, "%s=%lf ", elem.first.c_str(), val);
                    }
                    else {
                        offset += snprintf(sqlArr + offset, SqliteDB::SQL_LEN - offset, "%s=%lf,", elem.first.c_str(), val);
                    }
                    break;
                }
            default:	
                break;
        }

        ++i;
    }

    offset += snprintf(sqlArr + offset, SqliteDB::SQL_LEN - offset, "WHERE id=%llu;", GetID());
    if ( offset >= SqliteDB::SQL_LEN) {
        return false;
    }

    return SqliteDB::Instance()->ExecuteSqlEx(callback);
}

bool OrmProxy::InsertToDB(const std::string &_strTable, OrmDBCallBack *callback)
{
    char *sqlArr = SqliteDB::Instance()->GetSqlArray();
    snprintf(sqlArr, SqliteDB::SQL_LEN, "SELECT * FROM %s;", _strTable.c_str());
    return SqliteDB::Instance()->ExecuteSqlEx(callback);
}

bool OrmProxy::DelFromDB(const std::string &_strTable, OrmDBCallBack *callback)
{
    char *sqlArr = SqliteDB::Instance()->GetSqlArray();
    size_t offset = snprintf(sqlArr, SqliteDB::SQL_LEN, "DELETE FROM %s WHERE id=%llu", _strTable.c_str(), GetID());
    if ( offset >= SqliteDB::SQL_LEN) {
        return false;
    }

    return SqliteDB::Instance()->ExecuteSqlEx(callback);
}

void OrmProxy::AssignField(const char *column, const char *data)
{
    if (nullptr == column || nullptr == data) {
        return;
    }

    if (strcmp("id", column) == 0) {
        SetID(StringUtil::ConvertToValue<Real64>(data));
        return;
    }

    auto itr = _objFieldType.find(column);
    if (itr != _objFieldType.end()) {
        switch ( itr->second ) {
            case AnyType_String:	
                {
                    std::string &strData = *reinterpret_cast<std::string *>(_objFieldPt[itr->first]);
                    strData = data;
                }
            case AnyType_Int8:
                {
                    Int8 &val = *reinterpret_cast<Int8 *>(_objFieldPt[itr->first]);
                    val = atoi(data);
                }
            case AnyType_Int16:
                {
                    Int16 &val = *reinterpret_cast<Int16 *>(_objFieldPt[itr->first]);
                    val = atoi(data);
                }
            case AnyType_UInt16:
                {
                    UInt16 &val = *reinterpret_cast<UInt16 *>(_objFieldPt[itr->first]);
                    val = atoi(data);
                }
            case AnyType_Int32:
                {
                    Int32 &val = *reinterpret_cast<Int32 *>(_objFieldPt[itr->first]);
                    val = atoi(data);
                }
            case AnyType_UInt32:
                {
                    UInt32 &val = *reinterpret_cast<UInt32 *>(_objFieldPt[itr->first]);
                    val = atoi(data);
                }
            case AnyType_Int64:
                {
                    Int64 &val = *reinterpret_cast<Int64 *>(_objFieldPt[itr->first]);
                    val = StringUtil::ConvertToValue<Int64>(data);
                }
            case AnyType_UInt64:
                {
                    UInt64 &val = *reinterpret_cast<UInt64 *>(_objFieldPt[itr->first]);
                    val = StringUtil::ConvertToValue<UInt64>(data);
                }
            case AnyType_Real32:
                {
                    Real32 &val = *reinterpret_cast<Real32 *>(_objFieldPt[itr->first]);
                    val = StringUtil::ConvertToValue<Real32>(data);
                }
            case AnyType_Real64:
                {
                    Real64 &val = *reinterpret_cast<Real64 *>(_objFieldPt[itr->first]);
                    val = StringUtil::ConvertToValue<Real64>(data);
                }
            default:	
                break;
        }
    }
}
