#ifndef NANOSTDIO_H_
#define NANOSTDIO_H_

#ifdef __cplusplus
extern "C" {
#endif

int nanoprintf(const char *format, ...);
int nanoputs(const char *str);

#define printf nanoprintf
#define puts nanoputs

#ifdef __cplusplus
} // extern C
#endif

#endif // NANOSTDIO_H_
