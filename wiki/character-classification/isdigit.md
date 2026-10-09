# isdigit

> Sources: Michael Kerrisk, 2026-08-14
> Raw: ../../raw/character-classification/isdigit-3p.md
> Updated: 2026-08-14

## Overview

The `isdigit()` function tests whether a given character is a decimal digit (0-9). It is defined in `<ctype.h>` and respects the locale setting, returning non-zero if the character is a digit and 0 otherwise.

## Description

`isdigit()` checks if character `c` belongs to the `digit` character class in the current locale. The function is aligned with the ISO C standard and POSIX.1-2017. The argument must be representable as `unsigned char` or `EOF`; otherwise, behavior is undefined. The `isdigit_l()` variant accepts an explicit locale object.

Key points:
- Returns non-zero if `c` is a decimal digit (0-9)
- Returns 0 otherwise
- Locale-aware classification
- Undefined behavior for invalid inputs
- Part of `<ctype.h>` character classification family

## See Also

- [isalpha](isalpha.md) — test for an alphabetic character
- [isalnum](isalnum.md) — test for an alphanumeric character
- [isascii](isascii.md) — test for a 7-bit US-ASCII character
- [isprint](isprint.md) — test for a printable character
- [isspace](isspace.md) — test for a white-space character