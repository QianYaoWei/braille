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

    bool SelectFromDB(const std::string &strTable, OrmDBCallBack *callback);

    bool SyncDataToDB(const std::string &strTable, OrmDBCallBack *callback = nullptr);

    bool InsertToDB(const std::string &strTable, OrmDBCallBack *callback = nullptr);

    bool DelFromDB(const std::string &strTable, OrmDBCallBack *callback = nullptr);

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

    UInt64 _id {0};
    std::map<std::string, void *> _objFieldPt;
    std::map<std::string, utility::AnyType> _objFieldType;
};

typedef std::shared_ptr<OrmProxy> OrmProxySptr;


#define GETTER_SETTER(type, attr) \
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
    type attr; \
public:


#define GETTER_SETTER_DEF(type, attr, def) \
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
protected: \
    type attr {def}; \
public:
