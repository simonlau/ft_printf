# memchr

> Sources: Michael Kerrisk, 2026-08-14
> Raw: ../../raw/string-functions/2026-08-10-memchr-3.md
> Updated: 2026-08-14

## Overview

The `memchr()` function scans an area of memory for the first occurrence of a specified character. It is part of the Standard C library (`<string.h>`) and is thread-safe.

## Description

`memchr()` scans the initial `n` bytes of the memory area pointed to by `s` for the first instance of `c`. Both `c` and the bytes of the memory area are interpreted as `unsigned char`. The function is standardized in C11 and POSIX.1-2008, with historical roots in C89, SVr4, and 4.3BSD.

Key points:
- Scans initial `n` bytes for first instance of `c`
- Returns a pointer to the matching byte or NULL if not found
- Thread-safe (MT-Safe)
- Part of the Standard C library (`libc`, `-lc`)
- Includes `<string.h>`
- Useful for searching within binary data (not just strings)
