#include "py_stript_interface.h"

PyScriptInterface::PyScriptInterface ()
{
}

PyScriptInterface::~PyScriptInterface ()
{
    if (_pyModule) {
        Py_DECREF(_pyModule);
    }

    if (_pyModuleDict) {
        Py_DECREF(_pyModuleDict);
    }

    if (_pFunc) {
        Py_DECREF(_pFunc);
    }

    Py_Finalize();
}

bool PyScriptInterface::Init(const std::string &pyFile)
{
    int nRet = -1;
    _pyFileName = pyFile;

    do
    {
        // 初始化Python
        // 在使用Python系统前，必须使用Py_Initialize对其
        // 进行初始化。它会载入Python的内建模块并添加系统路
        // 径到模块搜索路径中。这个函数没有返回值，检查系统
        // 是否初始化成功需要使用Py_IsInitialized。
        Py_Initialize();
        // 检查初始化是否成功
        if (!Py_IsInitialized()) {
            break;
        }

        // 添加当前路径
        // 把输入的字符串作为Python代码直接运行，返回
        // 表示成功，-1表示有错。大多时候错误都是因为字符串
        // 中有语法错误。
        //
        PyRun_SimpleString("import sys");
        PyRun_SimpleString("sys.path.append('../script/')");

        if ( !LoadScript() ) {
            printf("load script error!\n");
        }

        // PyObject* pArgs = pArgs = Py_BuildValue("ii",  12,  14);
        // PyObject* pRet = PyEval_CallObject(_pFunc, pArgs);

        PyObject *pArgStr = PyString_FromString("/Users/terencewei/gitsrc/python-pinyin/file");
        if ( nullptr == pArgStr ) {
            printf("argstr error\n");
        }

        // PyObject* pRet = PyEval_CallObject(_pFunc, pArgStr);
        PyObject* pRet = PyEval_CallObject(_pFunc, pArgStr);

        // if (pArgStr) {
        //     Py_DECREF(pArgStr);
        // }

        // int a = 0; 
        // int b = 0;
        // if (pRet && PyArg_ParseTuple(pRet, "ii",  &a, &b)) {
        //     printf("Function[AddMult] call successful a + b = %d,  a * b = %d\n",  a,  b);
        //     nRet = 0;
        // }

        // if (pArgs) Py_DECREF(pArgs);

        // if (_pFunc) Py_DECREF(_pFunc);

        // // 找出函数名为HelloWorld的函数
        // _pFunc = PyDict_GetItemString(_pyModuleDict,  "HelloWorld");
        // if (!_pFunc || !PyCallable_Check(_pFunc)) { 
        //     printf("can't findfunction [HelloWorld]\n");
        //     break;
        // }

        // pArgs = Py_BuildValue("(s)",  "magictong");
        // PyEval_CallObject(_pFunc, pArgs);

    } while (false);

    return true;
}

bool PyScriptInterface::LoadScript()
{
    // 载入名为PyPlugin的脚本
    PyObject *pName = PyString_FromString(_pyFileName.c_str());
    if ( nullptr == pName ) {
        printf("false\n");
        return false;
    }
    _pyModule = PyImport_Import(pName);

    if (pName) {
        Py_DECREF(pName);
    }

    if (!_pyModule) {
        printf("can't find script\n");
        return false;
    }

    _pyModuleDict = PyModule_GetDict(_pyModule); 
    if (!_pyModuleDict) {
        return false;
    }

    // 找出函数名为FromNLToBraille的函数
    _pFunc = PyDict_GetItemString(_pyModuleDict, "FromNLToBraille");
    if (!_pFunc || !PyCallable_Check(_pFunc)) {
        printf("can't find function \n");
        return false;
    }

    return true;
}
