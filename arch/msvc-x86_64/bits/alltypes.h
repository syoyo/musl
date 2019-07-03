#define _Addr long
#define _Int64 long
#define _Reg long

//typedef __builtin_va_list va_list;
//typedef __builtin_va_list __isoc_va_list;
#define __isoc_va_list ...

#ifndef __cplusplus
// FIXME(syoyo): Use windows.h?
typedef short wchar_t;
#endif

#if defined(__FLT_EVAL_METHOD__) && __FLT_EVAL_METHOD__ == 2
TYPEDEF long double float_t;
TYPEDEF long double double_t;
#else
typedef float float_t;
typedef double double_t;
#endif

//typedef struct { long long __ll; long double __ld; } max_align_t;

typedef long time_t;
typedef long suseconds_t;

#if 0 // TODO(syoyo):
TYPEDEF struct { union { int __i[14]; volatile int __vi[14]; unsigned long __s[7]; } __u; } pthread_attr_t;
TYPEDEF struct { union { int __i[10]; volatile int __vi[10]; volatile void *volatile __p[5]; } __u; } pthread_mutex_t;
TYPEDEF struct { union { int __i[10]; volatile int __vi[10]; volatile void *volatile __p[5]; } __u; } mtx_t;
TYPEDEF struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; } pthread_cond_t;
TYPEDEF struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; } cnd_t;
TYPEDEF struct { union { int __i[14]; volatile int __vi[14]; void *__p[7]; } __u; } pthread_rwlock_t;
TYPEDEF struct { union { int __i[8]; volatile int __vi[8]; void *__p[4]; } __u; } pthread_barrier_t;
#endif

// forward decl.
typedef struct _FILE FILE;

typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed long long int64_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
