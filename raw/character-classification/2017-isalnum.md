# isalnum(3p) - POSIX Programmer's Manual

> Source: https://man7.org/linux/man-pages/man3/isalnum.3p.html
> Collected: 2026-08-14
> Published: 2017

This manual page is part of the POSIX Programmer's Manual. The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or the interface may not be implemented on Linux.

## NAME
isalnum, isalnum_l — test for an alphanumeric character

## SYNOPSIS
#include <ctype.h>

int isalnum(int c);
int isalnum_l(int c, locale_t locale);

## DESCRIPTION
The isalnum() and isalnum_l() functions shall test whether c is a character of class alpha or digit in the current locale, or in the locale represented by locale, respectively; see the Base Definitions volume of POSIX.1‐2017, Chapter 7, Locale.

The c argument is an int, the value of which the application shall ensure is representable as an unsigned char or equal to the value of the macro EOF. If the argument has any other value, the behavior is undefined.

The behavior is undefined if the locale argument to isalnum_l() is the special locale object LC_GLOBAL_LOCALE or is not a valid locale object handle.

## RETURN VALUE
The isalnum() and isalnum_l() functions shall return non-zero if c is an alphanumeric character; otherwise, they shall return 0.

## ERRORS
No errors are defined.

## EXAMPLES
None.

## APPLICATION USAGE
To ensure applications portability, especially across natural languages, only these functions and the functions in the reference pages listed in the SEE ALSO section should be used for character classification.

## RATIONALE
None.

## FUTURE DIRECTIONS
None.

## SEE ALSO
isalpha(3p), isblank(3p), iscntrl(3p), isdigit(3p), isgraph(3p), islower(3p), isprint(3p), ispunct(3p), isspace(3p), isupper(3p), isxdigit(3p), setlocale(3p), uselocale(3p)

The Base Definitions volume of POSIX.1‐2017, Chapter 7, Locale, ctype.h(0p), stdio.h(0p)

## COPYRIGHT
Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group Base Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.

IEEE/The Open Group 2017 ISALNUM(3P)