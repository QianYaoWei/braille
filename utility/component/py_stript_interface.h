/*
 * =====================================================================================
 *
 *       Filename:  py_stript_interface.h
 *
 *    Description:  python script interface, from mandarin to braille,
 *                  is done by pyton script
 *
 *        Created:  2016/10/26 16时07分31秒
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
#include <memory>
#include <vector>
#include <Python.h>
#include "Singleton.h"
#include "TypeDefine.h"

typedef std::shared_ptr<PyObject> PyObjectSptr;

/*
 * =====================================================================================
 *        Class:  PyScriptInterface
 *  Description:  
 * =====================================================================================
 */
class PyScriptInterface : public utility::Singleton<PyScriptInterface>
{
    public:
        /* ====================  LIFECYCLE     ======================================= */
        PyScriptInterface ();
        ~PyScriptInterface ();

        bool Init(const std::string &scriptDir, const std::string &scriptName);

        bool LoadScript();

        void TranslateFile(const std::string &file, std::vector<UInt16> &retVec);
    protected:
        void GetIntList(PyObject *pyList, std::vector<UInt16> &retVec);

        PyObjectSptr _pyModule;
        PyObjectSptr _pyModuleDict;
        PyObjectSptr _pyFunc;

        std::string _pyFileName;
}; /* -----  end of class PyScriptInterface  ----- */

bool PyObjectClean(PyObject *obj);
