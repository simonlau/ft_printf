# toupper(3p) - POSIX Programmer's Manual

> Source: https://man7.org/linux/man-pages/man3/toupper.3p.html
> Collected: 2026-08-14
> Published: 2017

This manual page is part of the POSIX Programmer's Manual. The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or the interface may not be implemented on Linux.

## NAME
toupper, toupper_l — transliterate lowercase characters to uppercase

## SYNOPSIS
#include <ctype.h>

int toupper(int c);
int toupper_l(int c, locale_t locale);

## DESCRIPTION
The toupper() and toupper_l() functions have as a domain a type int, the value of which is representable as an unsigned char or the value of EOF. If the argument has any other value, the behavior is undefined.

If the argument of toupper() or toupper_l() represents a lowercase letter, and there exists a corresponding uppercase letter as defined by character type information in the current locale or in the locale represented by locale, respectively (category LC_CTYPE), the result shall be the corresponding uppercase letter.

All other arguments in the domain are returned unchanged.

The behavior is undefined if the locale argument to toupper_l() is the special locale object LC_GLOBAL_LOCALE or is not a valid locale object handle.

## RETURN VALUE
Upon successful completion, toupper() and toupper_l() shall return the uppercase letter corresponding to the argument passed; otherwise, they shall return the argument unchanged.

## ERRORS
No errors are defined.

## EXAMPLES
None.

## APPLICATION USAGE
None.

## RATIONALE
None.

## FUTURE DIRECTIONS
None.

## SEE ALSO
setlocale(3p), uselocale(3p)

The Base Definitions volume of POSIX.1‐2017, Chapter 7, Locale, ctype.h(0p), locale.h(0p)

## COPYRIGHT
Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group Base Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.

IEEE/The Open Group 2017 TOUPPER(3P)