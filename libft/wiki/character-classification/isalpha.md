# isalpha

> Sources: Michael Kerrisk, 2026-08-14
> Raw: ../../raw/character-classification/2017-isalpha.md
> Updated: 2026-08-14

## Overview

The `isalpha()` function tests whether a given character is an alphabetic character (a-z, A-Z, and locale-specific letters). It is defined in `<ctype.h>` and respects the locale setting.

## Description

`isalpha()` checks if character `c` belongs to the `alpha` character class in the current locale. In the standard "C" locale, it is equivalent to `(isupper(c) || islower(c))`. The function is aligned with the ISO C standard and POSIX.1-2017. The argument must be representable as `unsigned char` or `EOF`; otherwise, behavior is undefined. The `isalpha_l()` variant accepts an explicit locale object.

Key points:
- Returns non-zero if `c` is an alphabetic character
- Returns 0 otherwise
- Locale-aware classification
- In "C" locale, equivalent to `isupper(c) || islower(c)`
- Part of `<ctype.h>` character classification family