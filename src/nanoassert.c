#include "nanoassert.h"

#ifdef __linux__
#include <stdlib.h>
#endif

_Noreturn void __nanoassert_fail(const char *cond_str, const char *filename, int lineno, const char *funcname)
{
  (void)cond_str;
  (void)filename;
  (void)lineno;
  (void)funcname;

#ifdef __linux__
  abort();
#endif
}
