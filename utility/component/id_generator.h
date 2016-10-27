/*
 * =====================================================================================
 *
 *       Filename:  id_generator.h
 *
 *    Description:  used for generatoing id
 *
 *        Created:  2016/10/27 16时09分01秒
 *       Compiler:  clang
 *
 *         Author:  TerenceWei 
 *          EMAIL:  360326661@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#pragma once
#include <memory>
#include "TypeDefine.h"
#include "orm_proxy.h"

/*
 * =====================================================================================
 *        Class:  IDGenerator
 *  Description:  
 * =====================================================================================
 */
class IDGenerator : public OrmProxy
{
public:
    UInt64 GenerateID();

    virtual void DBFieldRegister();

private:
    DEFINE_SETTER_GETTER(UInt64, _curID, 1);
}; /* -----  end of class IDGenerator  ----- */

typedef std::shared_ptr<IDGenerator> IDGeneratorSptr;
