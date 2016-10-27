#pragma once

#include <cstdio>
#include <cstring>

typedef char			Int8;
typedef unsigned char	UInt8;
typedef short			Int16;
typedef unsigned short	UInt16;
typedef int				Int32;
typedef unsigned int	UInt32;

#if defined(AVALON_COMPILER_MSVC)
typedef __int64			Int64;
typedef unsigned __int64	UInt64;
#else
typedef long long		Int64;
typedef unsigned long long	UInt64;
#endif

typedef float			Real32;
typedef	double			Real64;


#if defined(AVALON_COMPILER_MSVC)
#	define AVALON_INT64_FORMAT	"%I64d"
#	define AVALON_UINT64_FORMAT "%I64u"

#	define avalon_snprintf sprintf_s
#	define avalon_sscanf sscanf_s
#	define avalon_strncpy(d,s,l) strncpy_s(d,l+1,s,l)
#	define avalon_memmove(d,s,l) memmove_s(d,l,s,l)
#	define avalon_vsnprintf(d,l,f,a) vsnprintf_s(d,l,_TRUNCATE,f,a)
#	define avalon_atoll(s) _atoi64(s)
#	define avalon_strdup(s) _strdup(s)

#else
#	define AVALON_INT64_FORMAT "%lld"
#	define AVALON_UINT64_FORMAT "%llu"

#	define avalon_snprintf snprintf
#	define avalon_sscanf sscanf
#	define avalon_strncpy strncpy
#	define avalon_memmove memmove
#	define avalon_vsnprintf vsnprintf
#	define avalon_atoll(s) atoll(s)
#	define avalon_strdup(s) strdup(s)
#endif


#define AVALON_DELETE(Ptr) \
    do{ \
        delete Ptr; \
        Ptr = NULL; \
    }while(false)

#define AVALON_DELETE_ARRAY(Ptr) \
    do { \
        delete[] Ptr; \
        Ptr = NULL; \
    }while(false)

/**
 *@brief 一些常量定义
 */
#define AVALON_PI 3.141592653589793f
