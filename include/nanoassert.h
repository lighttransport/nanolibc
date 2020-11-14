#ifndef NANOASSERT_H_
#define NANOASSERT_H_

#undef assert

#ifdef NDEBUG
#define assert(x) (void)0
#else
#ifdef _MSC_VER

extern void _assert(
   char const* message,
   char const* filename,
   unsigned line
);

#define assert(x) ((void)((x) || (_assert(#x, __FILE__, __LINE__), 0)))
#else
#define assert(x) ((void)((x) || (__nanoassert_fail(#x, __FILE__, __LINE__, __func__), 0)))
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_MSC_VER)
#define NANOLIBC_NORETURN
#else
#define NANOLIBC_NORETURN _Noreturn
#endif

// _Noreturn = C11 keyword
NANOLIBC_NORETURN void __nanoassert_fail(const char *, const char *, int, const char *);

#ifdef __cplusplus
} // extern C
#endif

#endif // NANOSTDIO_H_
