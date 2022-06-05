# nanolibc, Nanoscale libc implementation

`nanolibc` is a small subset of standard C library(libc) implementation.

`nanolibc`'s primal usage is for embedded C programs and adding cross-platform JIT compilation of C/C++ application to your C/C++ application(MSVC, Linux, macOS)

## Requirements

* C11 compiler

## Supported platform

* Windows(MSVCRT) : Most of libc functions are deligated to the function in MSVCRT.
* Linux : Use musl implementation.
* macOS : T.B.D.

## Supported functions

### C90

* nanoassert.h
  * [ ] assert
* nanoctype.h
  * [ ] isalnum
  * [ ] isalpha
  * [ ] isblank
  * [ ] iscntrl
  * [ ] isdigit
  * [ ] isgraph
  * [ ] islower
  * [ ] isprint
  * [ ] ispunct
  * [ ] isspace
  * [ ] isupper
  * [ ] isxdigit
* nanoerrono.h
  * [ ] errno
* [ ] nanofloat.h
* [ ] nanoiso646.h
* [ ] nanolimits.h
* [ ] nanolocale.h
* [ ] nanosetjmp.h
* [ ] nanosignal.h
* [ ] nanostdarg.h
* [ ] nanostddef.h
* nanostdio.h
  * [ ] remove
  * [ ] rename
  * [ ] tmpfile
  * [ ] tmpnam
  * [ ] fclose
  * [ ] fflush
  * [ ] fopen
  * [ ] freopen
  * [ ] setbuf
  * [ ] setvbuf
  * [ ] fprintf
  * [ ] fscanf
  * [x] printf
  * [ ] scanf
  * [ ] snprintf
  * [ ] sprintf
  * [ ] sscanf
  * [ ] vfprintf
  * [ ] vfscanf
  * [ ] vprintf
  * [ ] vscanf
  * [ ] vsnprintf
  * [ ] vsprintf
  * [ ] vsscanf
  * [ ] fgetc
  * [ ] fgets
  * [ ] fputc
  * [ ] fputs
  * [ ] getc
  * [ ] getchar
  * [ ] gets
  * [ ] putc
  * [ ] putchar
  * [ ] puts
  * [ ] ungetc
  * [ ] fread
  * [ ] fwrite
  * [ ] fgetpos
  * [ ] fseek
  * [ ] fsetpos
  * [ ] ftell
  * [ ] rewind
  * [ ] clearerr
  * [ ] feof
  * [ ] ferror
  * [ ] perror
* nanostdlib.h
  * [ ] atof
  * [ ] atoi
  * [ ] atol
  * [ ] atoll(C++11)
  * [ ] strtod
  * [ ] strtof(C++11)
  * [ ] strtol
  * [ ] strtold(C++11)
  * [ ] strtoll(C++11)
  * [ ] strtoul
  * [ ] strtoull(C++11)
* nanostring.h
  * [ ] memcpy
  * [ ] memmove
  * [ ] strcpy
  * [ ] strncpy
  * [ ] strcat
  * [ ] strncat
  * [ ] memcmp
  * [ ] strcmp
  * [ ] strcoll
  * [ ] strncmp
  * [ ] strxfrm
  * [ ] memchr
  * [ ] strchr
  * [ ] strcspn
  * [ ] strpbrk
  * [ ] strchr
  * [ ] strspn
  * [ ] strstr
  * [ ] strtok
  * [ ] memset
  * [ ] sterror
  * [ ] strlen
  * [ ] NULL
* nanotime.h

### C11

* [ ] fenv.h
* [ ] inttypes.h
* [ ] stdbool.h
* [ ] stdint.h
* [ ] tgmath.h
* [ ] uchar.h

### Threads

* [ ] threads.h
  * [ ] Win32 thread
  * [ ] posix thread
  * [ ] OS-specific thread

### Wide characters

* [ ] wchar.h
* [ ] wctype.h

### libm

* MSVCRT: Use MSVCRT's math implementation


## Build samples/tests

nanolibc uses meson to build samples/tests.
Please install meson(https://mesonbuild.com/) and ninjaa(https://ninja-build.org/)

### Linux

Edit `scripts/bootstrap-linux.sh`, then

```
$ ./scripts/bootstrap-linux.sh
$ cd build
$ ninja
```

## TODO

* [ ] Support compilation on C89 compiler.
* [ ] WASI support.


## License

MIT license.

### Third party licenses

musl : MIT license.
libs/thread.h : MIT license or public domain https://github.com/mattiasgustavsson/libs
nanoprintf : Public domain https://github.com/charlesnicholson/nanoprintf
