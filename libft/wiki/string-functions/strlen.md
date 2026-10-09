# strlen

> Sources: Michael Kerrisk, 2026-08-14
> Raw: ../../raw/string-functions/2026-08-10-strlen-3.md
> Updated: 2026-08-14

## Overview

The `strlen()` function calculates the length of a string, excluding the terminating null byte. It is part of the Standard C library (`<string.h>`) and is thread-safe.

## Description

`strlen()` computes the length of the string pointed to by `s`, excluding the terminating null byte (`'\0'`). The function is equivalent to `strnul(s) - s`. It is standardized in C11 and POSIX.1-2008, with historical roots in C89, SVr4, and 4.3BSD.

Key points:
- Returns the number of bytes in the string (excluding `'\0'`)
- Thread-safe (MT-Safe)
- Part of the Standard C library (`libc`, `-lc`)
- Includes `<string.h>`
- Standardized in C11, POSIX.1-2008

## See Also

- [string(3)](string-functions/string.md) — string operations
- [strnul(3)](string-functions/strnul.md) — find length of prefix not containing given character
- [wcslen(3)](string-functions/wcslen.md) — wide-character string length