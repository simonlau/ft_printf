# strncmp

> Sources: Michael Kerrisk, 2026-08-14
> Raw: ../../raw/string-functions/2026-08-10-strncmp-3.md
> Updated: 2026-08-14

## Overview

The `strncmp()` function compares two strings, up to a specified number of bytes. It is part of the Standard C library (`<string.h>`) and is thread-safe.

## Description

`strncmp()` is similar to `strcmp()`, except it compares only the first (at most) `n` bytes of `s1` and `s2`. The function is equivalent to `memcmp(s1, s2, MIN(MIN(strnlen(s1,n),strnlen(s2,n))+1, n))`. It is standardized in C11 and POSIX.1-2008, with historical roots in C89, SVr4, and 4.3BSD.

Key points:
- Compares first `n` bytes of `s1` and `s2`
- Returns an integer less than, equal to, or greater than zero
- Thread-safe (MT-Safe)
- Part of the Standard C library (`libc`, `-lc`)
- Includes `<string.h>`
- Standardized in C11, POSIX.1-2008
- Complement of `memcmp()` for string comparison with length limit
