# strrchr

> Sources: Michael Kerrisk, 2026-08-14
> Raw: ../../raw/string-functions/2026-08-10-strrchr-3.md
> Updated: 2026-08-14

## Overview

The `strrchr()` function returns a pointer to the last occurrence of a character in a string. It is part of the Standard C library (`<string.h>`) and is thread-safe.

## Description

`strrchr()` returns a pointer to the last occurrence of the character `c` in the string `s`. The function is equivalent to `memrchr(s, c, strlen(s) + 1)`. It is standardized in C11 and POSIX.1-2008, with historical roots in C89, SVr4, and 4.3BSD.

Key points:
- Returns a pointer to the last occurrence of `c` in `s`
- Returns NULL if the character is not found
- Thread-safe (MT-Safe)
- Part of the Standard C library (`libc`, `-lc`)
- Includes `<string.h>`
- Standardized in C11, POSIX.1-2008
- Complement of `strchr()` (first occurrence)
