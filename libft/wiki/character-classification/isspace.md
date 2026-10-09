# isspace

> Sources: Michael Kerrisk, 2026-08-14
> Raw: ../../raw/character-classification/isspace-3p.md
> Updated: 2026-08-14

## Overview

The `isspace()` function tests whether a given character is a white-space character. It is defined in `<ctype.h>` and respects the locale setting, returning non-zero if the character is whitespace and 0 otherwise.

## Description

`isspace()` checks if character `c` belongs to the `space` character class in the current locale. The function is aligned with the ISO C standard and POSIX.1-2017. The argument must be representable as `unsigned char` or `EOF`; otherwise, behavior is undefined. The `isspace_l()` variant accepts an explicit locale object.

Key points:
- Returns non-zero if `c` is a white-space character
- Returns 0 otherwise
- Locale-aware classification
- Undefined behavior for invalid inputs
- Part of `<ctype.h>` character classification family
- Related to `isdigit()` but tests for whitespace instead of digits

## See Also

- [isalpha](isalpha.md) — test for an alphabetic character
- [isalnum](isalnum.md) — test for an alphanumeric character
- [isascii](isascii.md) — test for a 7-bit US-ASCII character
- [isdigit](isdigit.md) — test for a decimal digit
- [isprint](isprint.md) — test for a printable character