#pragma once
#include "UnCopyable.h"

namespace utility
{
    template<typename T>
    class Singleton : public UnCopyable
    {
    public:
        static T* Instance()
        {
            if(s_pInstance == 0)
            {
                s_pInstance = new T;
            }
            return s_pInstance;
        }

        static void Destroy()
        {
            delete s_pInstance;
            s_pInstance = 0;
        }

    private:
        static T* s_pInstance;

        class DestroyHelper
        {
            ~DestroyHelper()
            {
                Singleton<T>::Destroy();
            }
        };
        static DestroyHelper s_Helper;
    };

    template<typename T>
        T* Singleton<T>::s_pInstance = 0;

    template<typename T>
        typename Singleton<T>::DestroyHelper Singleton<T>::s_Helper;
}
