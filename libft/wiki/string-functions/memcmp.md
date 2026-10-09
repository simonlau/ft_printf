# memcmp

> Sources: Michael Kerrisk, 2026-08-14
> Raw: ../../raw/string-functions/2026-08-10-memcmp-3.md
> Updated: 2026-08-14

## Overview

The `memcmp()` function compares two memory areas byte by byte. It is part of the Standard C library (`<string.h>`) and is thread-safe.

## Description

`memcmp()` compares the first `n` bytes (each interpreted as `unsigned char`) of the memory areas `s1` and `s2`. The function is standardized in C11 and POSIX.1-2008, with historical roots in C89, SVr4, and 4.3BSD.

Key points:
- Compares first `n` bytes of `s1` and `s2` (as `unsigned char`)
- Returns an integer less than, equal to, or greater than zero
- If `n` is zero, returns zero
- Thread-safe (MT-Safe)
- Part of the Standard C library (`libc`, `-lc`)
- Includes `<string.h>`
- Caveat: do NOT use for confidential data (timing-based side-channel attacks)
