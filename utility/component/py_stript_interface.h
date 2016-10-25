#pragma once
#include "Singleton.h"
#include <Python.h>
#include <string>

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
        PyScriptInterface ();                             /* constructor */
        ~PyScriptInterface ();                             /* constructor */

        bool Init(const std::string &pyFile);
        bool LoadScript();
        // PyObject *PyCall();
    protected:
        PyObject *_pyModule {nullptr};
        PyObject *_pyModuleDict {nullptr};
        PyObject *_pFunc {nullptr};

        std::string _pyFileName;
}; /* -----  end of class PyScriptInterface  ----- */

