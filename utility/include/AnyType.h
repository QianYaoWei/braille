/*
 * =====================================================================================
 *
 *       Filename:  AnyType.h
 *
 *    Description:  
 *
 *        Created:  2016/10/27 15时23分01秒
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
#include "TypeDefine.h"

namespace utility
{
    enum AnyType
    {
        AnyType_Begin = 0,
        AnyType_Int8 = 1,
        AnyType_UInt8 = 2,
        AnyType_Int16 = 3,
        AnyType_UInt16 = 4,
        AnyType_Int32 = 5,
        AnyType_UInt32 = 6,
        AnyType_Int64 = 7,
        AnyType_UInt64 = 8,
        AnyType_Real32 = 9,
        AnyType_Real64 = 10,
        AnyType_String = 11,
        // AnyType_ComplexString,

        AnyType_End
    };

    union AnyUnion
    {
        AnyUnion() {}

        ~AnyUnion() {}

        Int8        valInt8;
        UInt8       valUInt8;
        Int16       valInt16;
        UInt16      valUInt16;
        Int32       valInt32;
        UInt32      valUInt32;
        Int64       valInt64;
        UInt64      valUInt64;
        Real32      valReal32;
        Real64      valReal64;
        // CLPosition  valPosition;
        char        *valString;
    };

    class AnyData
    {
        public:
            AnyData() : _valType(AnyType_Begin)
        {
            _val.valString = NULL;
        }

            ~AnyData()
            {
                if ((_valType == AnyType_String) &&
                        NULL != _val.valString) {

                    delete [] _val.valString;
                    _val.valString = NULL;
                }
            }

            AnyType GetAnyType()
            {
                return _valType;
            }

            const AnyUnion  &GetValue()
            {
                return _val;
            }

            template<typename T>
                void operator = (T &val)
                {
                    if ((_valType == AnyType_String) &&
                            NULL != _val.valString) {

                        delete [] _val.valString;
                        _val.valString = NULL;
                    }

                    this->Assign(val);
                }

        private:
            void Assign(const Int8 &val)
            {
                _val.valInt8 = val;
                _valType = AnyType_Int8;
            }

            void Assign(const UInt8 &val)
            {
                _val.valUInt8 = val;
                _valType = AnyType_UInt8;
            }

            void Assign(const Int16 &val)
            {
                _val.valInt16 = val;
                _valType = AnyType_Int16;
            }

            void Assign(const UInt16 &val)
            {
                _val.valUInt16 = val;
                _valType = AnyType_UInt16;
            }

            void Assign(const Int32 &val)
            {
                _val.valInt32 = val;
                _valType = AnyType_Int32;
            }

            void Assign(const UInt32 &val)
            {
                _val.valUInt32 = val;
                _valType = AnyType_UInt32;
            }

            void Assign(const Int64 &val)
            {
                _val.valInt64 = val;
                _valType = AnyType_Int64;
            }

            void Assign(const UInt64 &val)
            {
                _val.valUInt64 = val;
                _valType = AnyType_UInt64;
            }

            void Assign(const Real32 &val)
            {
                _val.valReal32 = val;
                _valType = AnyType_Real32;
            }

            void Assign(const Real64 &val)
            {
                _val.valReal64 = val;
                _valType = AnyType_Real64;
            }

            // void Assign(const CLPosition &val)
            // {
            //     _val.valPosition = val;
            //     _valType = AnyType_Position;
            // }

            void Assign(const std::string &val)
            {
                _val.valString = new(std::nothrow) char[val.size() + 1];
                _valType = AnyType_String;

                if (NULL == _val.valString) {
                    return;
                }

                memmove(_val.valString, val.c_str(), val.size());
                _val.valString[val.size()] = '\0';
            }

            // void Assign(CLComplexProperty &val)
            // {
            //     std::ostringstream os;
            //     val.EncodeString(os);
            //     _val.valString = new(std::nothrow) char[os.str().size() + 1];
            //     _valType = AnyType_ComplexString;

            //     if (NULL == _val.valString) {
            //         return;
            //     }

            //     memmove(_val.valString, os.str().c_str(), os.str().size());
            //     _val.valString[os.str().size()] = '\0';
            // }

            AnyType _valType;
            AnyUnion _val;
    };
}
