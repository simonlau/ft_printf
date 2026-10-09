# memcpy

> Sources: Michael Kerrisk, 2026-08-14
> Raw: ../../raw/string-functions/2026-08-10-memcpy-3.md
> Updated: 2026-08-14

## Overview

The `memcpy()` function copies `n` bytes from one memory area to another. The source and destination must not overlap. It is part of the Standard C library (`<string.h>`) and is thread-safe.

## Description

`memcpy()` copies `n` bytes from memory area `src` to memory area `dest`. The memory areas must not overlap. Use `memmove()` if the memory areas do overlap. The function is standardized in C11 and POSIX.1-2008, with historical roots in C89, SVr4, and 4.3BSD.

Key points:
- Copies `n` bytes from `src` to `dest`
- Memory areas must not overlap (use `memmove` for overlap)
- Returns a pointer to `dest`
- Thread-safe (MT-Safe)
- Part of the Standard C library (`libc`, `-lc`)
- Includes `<string.h>`
- Caveat: using `memcpy()` with overlapping areas produces undefined behavior; glibc 2.13 had a bug where a performance optimization reversed copy order, breaking applications with overlapping buffers
