#pragma once

namespace utility
{
    class UnCopyable
    {
    protected:
        UnCopyable(){}
        ~UnCopyable(){}

    private:
        UnCopyable(const UnCopyable&);
        const UnCopyable& operator=(const UnCopyable&);
    };
}
