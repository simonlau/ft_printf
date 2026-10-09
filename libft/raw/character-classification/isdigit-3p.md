# isdigit(3p) - Linux manual page

> Source: https://man7.org/linux/man-pages/man3/isdigit.3p.html
> Collected: 2026-08-14
> Published: Unknown

This manual page is part of the POSIX Programmer's Manual. The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or the interface may not be implemented on Linux.

## NAME
isdigit, isdigit_l — test for a decimal digit

## SYNOPSIS
#include <ctype.h>

int isdigit(int c);
int isdigit_l(int c, locale_t locale);

## DESCRIPTION
For isdigit(): The functionality described on this reference page is aligned with the ISO C standard. Any conflict between the requirements described here and the ISO C standard is unintentional. This volume of POSIX.1‐2017 defers to the ISO C standard.

The isdigit() and isdigit_l() functions shall test whether c is a character of class digit in the current locale, or in the locale represented by locale, respectively; see the Base Definitions volume of POSIX.1‐2017, Chapter 7, Locale.

The c argument is an int, the value of which the application shall ensure is a character representable as an unsigned char or equal to the value of the macro EOF. If the argument has any other value, the behavior is undefined.

The behavior is undefined if the locale argument to isdigit_l() is the special locale object LC_GLOBAL_LOCALE or is not a valid locale object handle.

## RETURN VALUE
The isdigit() and isdigit_l() functions shall return non-zero if c is a decimal digit; otherwise, they shall return 0.

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
isalnum(3p), isalpha(3p), isblank(3p), iscntrl(3p), isgraph(3p), islower(3p), isprint(3p), ispunct(3p), isspace(3p), isupper(3p), isxdigit(3p)

The Base Definitions volume of POSIX.1‐2017, Chapter 7, Locale, ctype.h(0p), locale.h(0p)

## COPYRIGHT
Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group Base Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group. In the event of any discrepancy between this version and the original IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be obtained online at http://www.opengroup.org/unix/online.html.

Any typographical or formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report such errors, see https://www.kernel.org/doc/man-pages/reporting_bugs.html.

IEEE/The Open Group 2017 ISDIGIT(3P)