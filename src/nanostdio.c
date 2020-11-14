#include "nanostdio.h"

#include <stdarg.h>

#ifdef _MSC_VER
extern int vprintf(const char *format, va_list arg);
#else
#include <stdio.h>
#endif

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
  ret = vfprintf(stdout, format, ap);
  va_end(ap);

  return ret;
#endif
}

int nanoputs(const char *str)
{
  int ret = puts(str);
  return ret;
}
