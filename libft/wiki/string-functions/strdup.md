# strdup

> Sources: Michael Kerrisk, 2026-08-14
> Raw: ../../raw/string-functions/2026-08-10-strdup-3.md
> Updated: 2026-08-14

## Overview

The `strdup()` function returns a pointer to a new string that is a duplicate of the input string. Memory for the new string is obtained with `malloc()`. It is part of the Standard C library (`<string.h>`) and is thread-safe.

## Description

`strdup()` returns a pointer to a new string which is a duplicate of the string `s`. Memory for the new string is obtained with `malloc(3)`, and can be freed with `free(3)`. On success, it returns a pointer to the duplicated string. It returns NULL if insufficient memory was available. The function requires `_XOPEN_SOURCE >= 500` or `_POSIX_C_SOURCE >= 200809L`. It is standardized in POSIX.1-2008, with historical roots in SVr4, 4.3BSD-Reno, and POSIX.1-2001.

Key points:
- Returns a pointer to a new duplicate of string `s`
- Memory obtained with `malloc()`, must be freed with `free()`
- Returns NULL on insufficient memory
- Thread-safe (MT-Safe)
- Part of the Standard C library (`libc`, `-lc`)
- Includes `<string.h>`
- Standardized in POSIX.1-2008
- Caller is responsible for freeing the returned memory
