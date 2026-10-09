*This project has been created as part of the 42 curriculum by choolau.*

# ft_printf

## Description

`ft_printf` recodes the libc `printf()` function as a small static library
(`libftprintf.a`). It exposes a single function:

```c
int ft_printf(const char *, ...);
```

The function writes formatted output to standard output without any buffer
management and handles the conversions `cspdiuxX%`:

| Specifier | Output |
|-----------|--------|
| `%c` | single character |
| `%s` | string (`NULL` prints as `(null)`) |
| `%p` | `void *` pointer in hexadecimal format |
| `%d` / `%i` | signed decimal (base 10) |
| `%u` | unsigned decimal (base 10) |
| `%x` / `%X` | hexadecimal (base 16), lowercase / uppercase |
| `%%` | literal percent sign |

The return value is the number of bytes printed (`-1` on a `NULL` format).
Behavior is diffed against the original `printf()`.

The bonus stage adds the flags `-0.`, the field minimum width under all
conversions, plus `#`, `+`, and space — built from the start around a
`t_flags` parsing state (see `ft_printf_bonus.h`) so the naive
no-flags design never has to be rewritten.

> Status: DRAFT scaffold — the conversion handlers are placeholders
> returning `0` (see `/* TODO */` markers). Implement each handler,
> then diff against libc `printf()`.

## Instructions

Requirements: `cc`, `ar`, `make`.

```sh
make          # build libft via its Makefile, then libftprintf.a at root
make bonus    # rebuild including the bonus flag parsing
make clean    # remove object files (also inside libft/)
make fclean   # remove object files, libftprintf.a and libft/libft.a
make re       # rebuild from scratch
```

The top `Makefile` compiles the bundled `libft/` library through its own
`Makefile` first, then merges it into `libftprintf.a`, so the final archive
contains both. (To use your own completed libft, copy its sources and
`Makefile` over `libft/`.)

Compile your program against the library:

```sh
cc -Wall -Wextra -Werror main.c libftprintf.a -o prog
```

## Resources

- Subject: `docs/ft_printf.pdf` (42 ft_printf, Version 12.1).
- `man 3 printf` — format-string grammar, flags, width, precision, length
  modifiers, conversion specifiers, return value.
- `man 3 stdarg` — `va_start`, `va_arg`, `va_copy`, `va_end` semantics.
- Tutorial: GeeksforGeeks, "Variadic Functions in C" (10 Apr 2026) —
  the `va_list` declare/init/read/cleanup pattern.

### AI usage

An AI coding assistant (OpenCode / Muse Spark) was used for:

- Repository scaffolding: this `README.md` skeleton, the `Makefile`
  (`NAME`/`all`/`clean`/`fclean`/`re`/`bonus` rules, `ar rcs`), and the
  placeholder file layout (`ft_printf.h`, `ft_print_*.c`,
  `ft_printf_bonus.{c,h}`).
- Compiling the subject PDF and reference pages into `raw/` + `wiki/`
  study notes.

The actual conversion logic (`TODO` handlers), testing against libc
`printf()`, and Norm compliance are done by hand, in line with the
subject's AI instructions (reason first, peer learning, exam readiness).

## Algorithm and data structure

**Algorithm.** Single-pass scan of the format string with an index `i`
and a byte counter. Ordinary characters go straight to `ft_print_char`;
on `%`, the next character dispatches through `ft_handle_conversion`,
which maps each specifier to its handler via one `if/else` chain reading
the argument with the matching `va_arg` type (`int` for `%c`, `char *`
for `%s`, `void *` for `%p`, …). The bonus path inserts a flag-parsing
step between `%` and dispatch that fills a `t_flags` struct (left-align,
zero-pad, precision, width, `#`/`+`/space) consumed by the same handlers.

This was chosen because the conversion set is tiny and fixed — a dispatch
chain is O(1) per specifier, has no lookup table to keep in sync, and each
handler stays independently testable against `printf()` output.

**Data structures.** No heap allocation and no dynamic structures: the
only state is the `va_list` cursor plus (bonus) a stack-allocated
`t_flags` struct per conversion. Number-to-string conversion renders
digits into a small local buffer (or recursively), so there is nothing to
`free` and no leak surface — matching the subject's memory rules. The
extensibility point is the dispatcher: adding a specifier or flag means
one new branch plus one new handler, never a rewrite of the scan loop.
