#ifndef NANOASSERT_H_
#define NANOASSERT_H_

#undef assert

#ifdef NDEBUG
#define assert(x) (void)0
#else
#define assert(x) ((void)((x) || (__nanoassert_fail(#x, __FILE__, __LINE__, __func__), 0)))
#endif

#ifdef __cplusplus
extern "C" {
#endif

// _Noreturn = C11 keyword
_Noreturn void __nanoassert_fail(const char *, const char *, int, const char *);

#ifdef __cplusplus
} // extern C
#endif

#endif // NANOSTDIO_H_
