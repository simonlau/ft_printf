# strchr

> Sources: Michael Kerrisk, 2026-08-14
> Raw: ../../raw/string-functions/2026-08-10-strchr-3.md
> Updated: 2026-08-14

## Overview

The `strchr()` function returns a pointer to the first occurrence of a character in a string. It is part of the Standard C library (`<string.h>`) and is thread-safe.

## Description

`strchr()` returns a pointer to the first occurrence of the character `c` in the string `s`. The terminating null byte is considered part of the string, so if `c` is specified as `'\0'`, `strchr()` returns a pointer to the terminator. The function is equivalent to `memchr(s, c, strlen(s) + 1)`. It is standardized in C11 and POSIX.1-2008, with historical roots in C89, SVr4, and 4.3BSD.

Key points:
- Returns a pointer to the first occurrence of `c` in `s`
- Returns NULL if the character is not found
- Terminating null byte is considered part of the string
- Thread-safe (MT-Safe)
- Part of the Standard C library (`libc`, `-lc`)
- Includes `<string.h>`
- Standardized in C11, POSIX.1-2008
