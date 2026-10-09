# memset

> Sources: Michael Kerrisk, 2026-08-14
> Raw: ../../raw/string-functions/2026-08-10-memset-3.md
> Updated: 2026-08-14

## Overview

The `memset()` function fills the first `n` bytes of a memory area with a constant byte. It is part of the Standard C library (`<string.h>`) and is thread-safe.

## Description

`memset()` fills the first `n` bytes of the memory area pointed to by `a` with the constant byte `c`. It is standardized in C11 and POSIX.1-2008, with historical roots in C89, SVr4, and 4.3BSD.

Key points:
- Fills `n` bytes with constant byte `c`
- Returns a pointer to the memory area `a`
- Thread-safe (MT-Safe)
- Part of the Standard C library (`libc`, `-lc`)
- Includes `<string.h>`
- Caveat: compiler may remove the call if it deduces it is unnecessary
