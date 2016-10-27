/*
 * =====================================================================================
 *
 *       Filename:  orm_proxy.h
 *
 *    Description:  
 *
 *        Created:  2016/10/26 19时24分21秒
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
#include "TypeDefine.h"
#include "AnyType.h"

class OrmDBCallBack;

class OrmProxy
{
public:
    OrmProxy(UInt64 id = 0) : _id(id)
    {
    }

    virtual ~OrmProxy()
    {
    }

    UInt64 GetID() { return _id; }
    void SetID(UInt64 id) { _id = id; }

    virtual void DBFieldRegister() = 0;

    bool SelectFromDB(const std::string &_strTable, OrmDBCallBack *callback);

    bool SyncDataToDB(const std::string &_strTable, OrmDBCallBack *callback);

    bool InsertToDB(const std::string &_strTable, OrmDBCallBack *callback);

    bool DelFromDB(const std::string &_strTable, OrmDBCallBack *callback);

    void AssignField(const char *column, const char *data);
protected:
    template<typename T>
    void ObjAndDBMapping(const char *dbField, T &objField)
    {
        utility::AnyData filed;
        filed = objField;

        _objFieldPt[dbField] = &objField;
        _objFieldType[dbField] = filed.GetAnyType();
    }

    std::string _strTable;
    UInt64 _id {0};

    std::map<std::string, void *> _objFieldPt;
    std::map<std::string, utility::AnyType> _objFieldType;
};

typedef std::shared_ptr<OrmProxy> OrmProxySptr;


#define DEFINE_SETTER_GETTER(type, attr, def) \
public: \
    const type &Get##attr() \
    { \
        return attr; \
    } \
 \
    void Set##attr(const type &el) \
    { \
        attr = el; \
    } \
private: \
    type attr {def}; \
public:
