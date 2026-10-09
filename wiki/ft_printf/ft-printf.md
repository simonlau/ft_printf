# ft_printf

> Sources: 42 School, Unknown; man-pages project, 2026-02-16
> Raw: [ft-printf-subject-v12-1](../../raw/ft_printf/ft-printf-subject-v12-1.md); [printf-3-linux-manual-page](../../raw/ft_printf/2026-02-16-printf-3-linux-manual-page.md)
> Updated: 2026-10-09

## Overview

ft_printf is a 42 curriculum project to recode printf() from libc as a small variadic library, focused on well-structured and extensible C code. The subject version ingested here is Version: 12.1, and the reference behavior is grounded in the Linux printf(3) manual, which documents the full format-string machinery the 42 subset is compared against.

## Mandatory library

Build a library named libftprintf.a containing a function with the prototype:

int ft_printf(const char *, ...);

Turn-in set is Makefile, *.h, */*.h, *.c, */*.c, with Makefile targets NAME, all, clean, fclean, re. The archive must be created with ar; libtool is forbidden, and the resulting Your libftprintf.a has to be created at the root of your repository. The public header must be named ft_printf.h.

Only these external functions are allowed: malloc, free, write, va_start, va_arg, va_copy, va_end. Libft use is authorized via a copied libft folder built through its own Makefile. Compilation uses the flags -Wall, -Wextra, and -Werror, using cc, and the Makefile rules include $(NAME), all, clean, fclean and re without unnecessary relinking.

Key behavioral requirements:

- Do not implement the buffer management of the original printf().
- Your function has to handle the following conversions: cspdiuxX%
- Your function will be compared against the original printf().
- You must use the command ar to create your library.
- Using the libtool command is forbidden.

Conversions to implement:

- `%c` Prints a single character.
- `%s` Prints a string (as defined by the common C convention).
- `%p` with The void * pointer argument has to be printed in hexadecimal format.
- `%d` Prints a decimal (base 10) number.
- `%i` Prints an integer in base 10.
- `%u` Prints an unsigned decimal (base 10) number.
- `%x` Prints a number in hexadecimal (base 16) lowercase format.
- `%X` Prints a number in hexadecimal (base 16) uppercase format.
- `%%` Prints a percent sign.

## Reference behavior (libc printf)

The real printf lives in the Standard C library (libc, -lc) with the canonical declaration:

int printf(const char *restrict format, ...);

Siblings cover streams, file descriptors, and va_list callers: fprintf, dprintf, vprintf, vfprintf, vdprintf. The va_list variants are equivalent to the variadic ones except for how arguments arrive, and These functions do not call the va_end macro.

A format string mixes literal text with conversion specifications. The literals are ordinary characters (not %), which are copied unchanged to the output stream, while each specification follows one overall shape:

%[argument$][flags][width][.precision][length modifier]conversion

Flags control padding, justification, signs, and alternate forms. The interactions that matter most for the 42 bonus work are that If the 0 and - flags both appear, the 0 flag is ignored, that A - overrides a 0 if both are given, and that A + overrides a space if both are used. Width sets a minimum field, never truncating: In no case does a nonexistent or small field width cause truncation of a field. Precision is introduced by a dot: If the precision is given as just '.', the precision is taken to be zero, and A negative precision is taken as if the precision were omitted.

For the integer conversions in the 42 subset, the defaults are small: The default precision is 1, and When 0 is printed with an explicit precision 0, the output is empty. For floating-point output, If the precision is missing, it is taken as 6. Length modifiers select argument size, from hh and h up through l, ll, j, z, and t; q is just A synonym for ll, and Z is a legacy spelling its own manual marks with Do not use in new code (as is C, a Synonym for lc. Don't use).

The full conversion set is wider than the 42 subset: beyond cspdiuxX% the manual also documents o, e, E, f, F, g, G, a, A, C, S, n, and m. Two equivalences are worth remembering when testing against the original: The void * pointer argument is printed in hexadecimal (as if by %#x or %#lx), and for a literal percent sign No argument is converted. The complete conversion specification is '%%'.

Return and conformance: Upon successful return, these functions return the number of bytes printed (excluding the null byte used to end output to strings), while On error, a negative value is returned. The core family is standardized as fprintf(), printf(), vprintf(), vfprintf(): C11, POSIX.1-2008. History notes include that glibc 2.1 adds length modifiers hh, j, t, and z and conversion characters a and A.

One security warning from the manual applies to every printf reimplementation: passing user input as the format string often indicates a bug, since foo may contain a % character, and a hostile %n can turn the call into a memory write, creating a security hole.

## Common engineering rules

Code must be C and Norm-compliant, including bonus files; a norm error means 0. Crashes such as segmentation fault, bus error, or double free make the project non-functional except for undefined behavior. All heap memory must be freed; leaks are not tolerated. Bonus code lives in _bonus.{c/h} files behind a bonus Makefile rule, evaluated separately. Work is submitted to the assigned Git repository, with peer evaluation followed by Deepthought grading that stops on first error section.

## AI and learning rules

The subject frames this as foundational ICT training requiring reasoning before AI help, peer learning over answer-copying, and awareness that exams allow no AI. Learner rules include applying reasoning before AI, not asking AI for direct answers, and learning the 42 global approach on AI. Good practice is talking through a new concept with a peer; bad practice is secretly copying AI code that cannot be explained at evaluation or exam.

## README requirements

A README.md at the repo root is mandatory. Its very first line must be italicized and read:

This project has been created as part of the 42 curriculum by <login1>[, <login2>[, <login3>[...]]].

Required sections are Description, Instructions, and Resources including how AI was used, plus a detailed explanation and justification of the chosen algorithm and data structure. Additional sections such as usage examples or technical choices may be required when explicitly listed.

## Bonus

Optional flags work, assessed only when mandatory is perfect:

- Manage any combination of the following flags: '-0.' and the field minimum width under all conversions.
- Manage all the following flags: '# +' (Yes, one of them is a space)

The governing rule is: The bonus part will only be assessed if the mandatory part is PERFECT. Failing any mandatory requirement means the bonus is not evaluated at all.

## Submission and defense

Only repo contents are evaluated. After passing, ft_printf() may be added to libft for later C projects. Defense may request a brief modification of the project — a small behavior change or few-line feature — defined in the evaluation guidelines to verify understanding.
