# bzero

> Sources: Michael Kerrisk, 2026-08-14
> Raw: ../../raw/string-functions/2026-08-10-bzero-3.md
> Updated: 2026-08-14

## Overview

The `bzero()` function zeroes a byte array. It is equivalent to `memset(a, '\0', n)`. It originates from 4.3BSD and has been removed from POSIX.1-2008.

## Description

`bzero()` writes zeros (`'\0'`) to the memory starting at the location pointed to by `a`. It is equivalent to `memset(a, '\0', n)`. The function has no return value. It was marked as LEGACY in POSIX.1-2001 and removed in POSIX.1-2008. It is not part of any current standard.

Key points:
- Writes zeros to memory area `a` (first `n` bytes)
- Equivalent to `memset(a, '\0', n)`
- No return value
- Thread-safe (MT-Safe)
- Includes `<strings.h>`
- Not standardized (removed from POSIX.1-2008)
- Historical: 4.3BSD, LEGACY in POSIX.1-2001
- Use `memset()` or `explicit_bzero()` for new code
