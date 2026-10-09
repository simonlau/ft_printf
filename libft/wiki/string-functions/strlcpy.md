# strlcpy

> Sources: Michael Kerrisk, 2026-08-14
> Raw: ../../raw/string-functions/2026-07-11-strlcpy-3.md
> Updated: 2026-08-14

## Overview

The `strlcpy()` function copies a string to a destination buffer, truncating if necessary to fit. It returns the total length of the string it tried to create, allowing callers to detect truncation. It is part of the Standard C library (`<string.h>`) and was added in POSIX.1-2024.

## Description

`strlcpy()` copies the string pointed to by `src` into the buffer pointed to by `dst`. If the string doesn't fit in the buffer, it is truncated. The function returns the total length of the string it tried to create, as if truncation didn't happen. This allows callers to detect truncation by comparing the return value to the buffer size. The function originates from OpenBSD 2.4 and was standardized in POSIX.1-2024 (glibc 2.38).

Key points:
- Copies `src` to `dst` with truncation if needed
- Returns the total length of the string it tried to create
- Truncation is detectable by comparing return value to buffer size
- Part of the Standard C library (`libc`, `-lc`)
- Includes `<string.h>`
- Standardized in POSIX.1-2024, OpenBSD 2.4, glibc 2.38
- Caveat: vulnerable to DoS attacks since it reads the entire source string
