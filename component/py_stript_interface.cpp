#include "py_stript_interface.h"

bool PyObjectClean(PyObject *obj)
{
    if (obj) {
        Py_DECREF(obj);
    }

    return true;
}

PyScriptInterface::PyScriptInterface ()
{
}

PyScriptInterface::~PyScriptInterface ()
{
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

        PyRun_SimpleString("import sys");
        PyRun_SimpleString("sys.path.append('../script/')");
        if ( !LoadScript() ) {
            printf("load script error!\n");
        }
        
        PyObjectSptr argsSptr(PyTuple_New(1), PyObjectClean);
        PyTuple_SetItem(argsSptr.get(),  0,  Py_BuildValue("s", "/Users/terencewei/gitsrc/python-pinyin/file"));

        if (!_pyFunc || !PyCallable_Check(_pyFunc.get())) { 
            printf("can't find function\n");
            break;
        }

        PyEval_CallObject(_pyFunc.get(), argsSptr.get());
    } while (false);

    return true;
}

bool PyScriptInterface::LoadScript()
{
    // 载入名为PyPlugin的脚本
    PyObjectSptr nameSptr(PyString_FromString(_pyFileName.c_str()), PyObjectClean);
    if (!nameSptr) {
        printf("false\n");
        return false;
    }

    _pyModule.reset(PyImport_Import(nameSptr.get()), PyObjectClean);

    if (!_pyModule) {
        printf("can't find script\n");
        return false;
    }

    _pyModuleDict.reset(PyModule_GetDict(_pyModule.get()), PyObjectClean); 
    if (!_pyModuleDict) {
        return false;
    }

    // 找出函数名为FromNLToBraille的函数
    _pyFunc.reset(PyDict_GetItemString(_pyModuleDict.get(), "FromNLToBraille"), PyObjectClean);
    if (!_pyFunc || !PyCallable_Check(_pyFunc.get())) {
        printf("can't find function \n");
        return false;
    }

    return true;
}
