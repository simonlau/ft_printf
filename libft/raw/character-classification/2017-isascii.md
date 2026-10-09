# isascii(3p) - POSIX Programmer's Manual

> Source: https://man7.org/linux/man-pages/man3/isascii.3p.html
> Collected: 2026-08-14
> Published: 2017

This manual page is part of the POSIX Programmer's Manual. The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or the interface may not be implemented on Linux.

## NAME
isascii — test for a 7-bit US-ASCII character

## SYNOPSIS
#include <ctype.h>

int isascii(int c);

## DESCRIPTION
The isascii() function shall test whether c is a 7-bit US-ASCII character code.

The isascii() function is defined on all integer values.

## RETURN VALUE
The isascii() function shall return non-zero if c is a 7-bit US-ASCII character code between 0 and octal 0177 inclusive; otherwise, it shall return 0.

## ERRORS
No errors are defined.

## EXAMPLES
None.

## APPLICATION USAGE
The isascii() function cannot be used portably in a localized application.

## RATIONALE
None.

## FUTURE DIRECTIONS
The isascii() function may be removed in a future version.

## SEE ALSO
The Base Definitions volume of POSIX.1‐2017, ctype.h(0p)

## COPYRIGHT
Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group Base Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.

IEEE/The Open Group 2017 ISASCII(3P)