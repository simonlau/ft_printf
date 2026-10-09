# tolower

> Sources: Michael Kerrisk, 2026-08-14
> Raw: ../../raw/character-classification/2017-tolower.md
> Updated: 2026-08-14

## Overview

The `tolower()` function transliterates an uppercase letter to its corresponding lowercase letter. It is defined in `<ctype.h>` and respects the locale setting.

## Description

`tolower()` converts an uppercase letter to the corresponding lowercase letter as defined by character type information in the current locale (category `LC_CTYPE`). If the argument does not represent an uppercase letter with a corresponding lowercase letter, it is returned unchanged. The function is aligned with the ISO C standard and POSIX.1-2017. The argument must be representable as `unsigned char` or `EOF`; otherwise, behavior is undefined. The `tolower_l()` variant accepts an explicit locale object.

Key points:
- Returns the lowercase letter corresponding to the argument
- Returns the argument unchanged if no corresponding lowercase letter exists
- Locale-aware conversion (category `LC_CTYPE`)
- Part of `<ctype.h>` character classification family
- Complement of `toupper()`
