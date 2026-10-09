# calloc

> Sources: Michael Kerrisk, 2026-08-14
> Raw: ../../raw/stdlib-functions/2026-02-08-calloc-3.md
> Updated: 2026-08-14

## Overview

The `calloc()` function allocates memory for an array of elements and initializes all bytes to zero. It is part of the Standard C library (`<stdlib.h>`) and is thread-safe.

## Description

`calloc()` allocates memory for an array of `n` elements of `size` bytes each and returns a pointer to the allocated memory. The memory is set to zero. If `n` or `size` is 0, `calloc()` returns a unique pointer value that can later be successfully passed to `free()`. If the multiplication of `n` and `size` would result in integer overflow, `calloc()` returns an error. The function is standardized in C23 and POSIX.1-2024, with historical roots in POSIX.1-2001 and C89.

Key points:
- Allocates memory for `n` elements of `size` bytes each
- Memory is set to zero (unlike `malloc()`)
- Returns NULL on error (integer overflow or out of memory)
- Thread-safe (MT-Safe)
- Part of the Standard C library (`libc`, `-lc`)
- Includes `<stdlib.h>`
- Standardized in C23, POSIX.1-2024
- Caller is responsible for freeing the returned memory with `free()`
