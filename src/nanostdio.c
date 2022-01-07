#include "nanostdio.h"

#include <stdarg.h>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat"
#endif

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"
#endif

#define NANOPRINTF_IMPLEMENTATION
#include "nanoprintf.h"

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

#ifdef __clang__
#pragma clang diagnostic pop
#endif


#ifdef _MSC_VER
extern int vprintf(const char *format, va_list arg);
#else
//#include <stdio.h>
#endif

static void __putc_fun(int c, void *ctx)
{
  // TODO
  (void)c;
  (void)ctx;
}

int nanoprintf(const char *format, ...)
{
#ifdef _MSC_VER
  va_list list;
  va_start(list, format);

  int ret = vprintf(format, list);
  va_end(list);

  return ret;
#else

  int ret;
  va_list ap;
  va_start(ap, format);
  ret = npf_vpprintf(__putc_fun, /* ctx */NULL, format, ap);
  va_end(ap);

  return ret;
#endif
}

int nanoputs(const char *str)
{
  int ret = puts(str);
  return ret;
}
