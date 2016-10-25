#pragma once
#include "Singleton.h"
#include <Python.h>
#include <string>
#include <memory>

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

        bool Init(const std::string &pyFile);
        bool LoadScript();
    protected:
        PyObjectSptr _pyModule;
        PyObjectSptr _pyModuleDict;
        PyObjectSptr _pyFunc;

        std::string _pyFileName;
}; /* -----  end of class PyScriptInterface  ----- */

bool PyObjectClean(PyObject *obj);
