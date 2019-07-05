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
* nanoctype.h
* nanoerrono.h
* nanofloat.h
* nanoiso646.h
* nanolimits.h
* nanolocale.h
* nanosetjmp.h
* nanosignal.h
* nanostdarg.h
* nanostddef.h
* nanostdio.h
  * [x] printf
* nanostdlib.h
* nanostring.h
* nanotime.h

### C11

T.B.W.

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

Support compilation on C89 compiler.


## License

MIT license.

### Third party licenses

musl : MIT license.
