# isascii

> Sources: Michael Kerrisk, 2026-08-14
> Raw: ../../raw/character-classification/2017-isascii.md
> Updated: 2026-08-14

## Overview

The `isascii()` function tests whether a given character is a 7-bit US-ASCII character (0–127). It is defined in `<ctype.h>` and is part of the POSIX.1-2001 (XSI) extension.

## Description

`isascii()` checks if character `c` is a 7-bit US-ASCII character code between 0 and octal 0177 inclusive. The function is defined on all integer values. Unlike other character classification functions, `isascii()` is not locale-aware. POSIX.1-2008 marks it as obsolete, noting it cannot be used portably in a localized application, and it may be removed in a future version. `isascii_l()` is a GNU extension.

Key points:
- Returns non-zero if `c` is a 7-bit ASCII character (0–127)
- Returns 0 otherwise
- Not locale-aware
- POSIX.1-2001 (XSI) extension
- Marked obsolete in POSIX.1-2008
- Cannot be used portably in localized applications