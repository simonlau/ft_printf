# atoi

> Sources: Michael Kerrisk, 2026-08-14
> Raw: ../../raw/stdlib-functions/2026-02-08-atoi-3.md
> Updated: 2026-08-14

## Overview

The `atoi()` function converts the initial portion of a string to an integer. It is part of the Standard C library (`<stdlib.h>`) and is thread-safe.

## Description

`atoi()` converts the initial portion of the string pointed to by `nptr` to `int`. The behavior is the same as `strtol(nptr, NULL, 10)`, except that `atoi()` does not detect errors. The `atol()` and `atoll()` functions behave the same as `atoi()`, except that they convert to `long` or `long long`. The function is standardized in C11 and POSIX.1-2008, with historical roots in C99, POSIX.1-2001, SVr4, and 4.3BSD.

Key points:
- Converts initial portion of string to `int`
- Equivalent to `strtol(nptr, NULL, 10)` but does not detect errors
- Returns the converted value or 0 on error
- Thread-safe (MT-Safe locale)
- Part of the Standard C library (`libc`, `-lc`)
- Includes `<stdlib.h>`
- Standardized in C11, POSIX.1-2008
- Caveat: no error detection, no overflow checks; use `strtol()` family for robust error handling
