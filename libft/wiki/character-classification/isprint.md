# isprint

> Sources: Michael Kerrisk, 2026-08-14
> Raw: ../../raw/character-classification/2017-isprint.md
> Updated: 2026-08-14

## Overview

The `isprint()` function tests whether a given character is a printable character (including space). It is defined in `<ctype.h>` and respects the locale setting.

## Description

`isprint()` checks if character `c` belongs to the `print` character class in the current locale. A printable character is one that can be displayed, including space. The function is aligned with the ISO C standard and POSIX.1-2017. The argument must be representable as `unsigned char` or `EOF`; otherwise, behavior is undefined. The `isprint_l()` variant accepts an explicit locale object.

Key points:
- Returns non-zero if `c` is a printable character (including space)
- Returns 0 otherwise
- Locale-aware classification
- Includes space as a printable character
- Part of `<ctype.h>` character classification family