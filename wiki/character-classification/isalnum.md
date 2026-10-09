# isalnum

> Sources: Michael Kerrisk, 2026-08-14
> Raw: ../../raw/character-classification/2017-isalnum.md
> Updated: 2026-08-14

## Overview

The `isalnum()` function tests whether a given character is an alphanumeric character (a letter or a decimal digit). It is defined in `<ctype.h>` and respects the locale setting.

## Description

`isalnum()` checks if character `c` belongs to the `alpha` or `digit` character class in the current locale. It is equivalent to `(isalpha(c) || isdigit(c))`. The function is aligned with the ISO C standard and POSIX.1-2017. The argument must be representable as `unsigned char` or `EOF`; otherwise, behavior is undefined. The `isalnum_l()` variant accepts an explicit locale object.

Key points:
- Returns non-zero if `c` is alphanumeric (letter or digit)
- Returns 0 otherwise
- Equivalent to `isalpha(c) || isdigit(c)`
- Locale-aware classification
- Part of `<ctype.h>` character classification family