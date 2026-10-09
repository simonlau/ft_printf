# toupper

> Sources: Michael Kerrisk, 2026-08-14
> Raw: ../../raw/character-classification/2017-toupper.md
> Updated: 2026-08-14

## Overview

The `toupper()` function transliterates a lowercase letter to its corresponding uppercase letter. It is defined in `<ctype.h>` and respects the locale setting.

## Description

`toupper()` converts a lowercase letter to the corresponding uppercase letter as defined by character type information in the current locale (category `LC_CTYPE`). If the argument does not represent a lowercase letter with a corresponding uppercase letter, it is returned unchanged. The function is aligned with the ISO C standard and POSIX.1-2017. The argument must be representable as `unsigned char` or `EOF`; otherwise, behavior is undefined. The `toupper_l()` variant accepts an explicit locale object.

Key points:
- Returns the uppercase letter corresponding to the argument
- Returns the argument unchanged if no corresponding uppercase letter exists
- Locale-aware conversion (category `LC_CTYPE`)
- Part of `<ctype.h>` character classification family
- Complement of `tolower()`
