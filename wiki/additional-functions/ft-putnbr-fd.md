# ft_putnbr_fd

> Sources: 42 school libft subject v19.3, 2026-09-28
> Raw: [libft-subject](../../raw/project-overview/libft-subject.md)
> Updated: 2026-09-28

## Overview

`ft_putnbr_fd` outputs the integer `n` to the specified file descriptor. Prototype: `void ft_putnbr_fd(int n, int fd)`.

## Parameters

- **n** — The integer to output.
- **fd** — The file descriptor on which to write.

## Return value

None. The subject lists `write` as the only external function — a libc call, not a Part 1 reimplementation.

## Implementation

Status: **not yet implemented** — `ft_putnbr_fd.c` is a stub.

Planned Part 1 functions (not yet in code): none — the conversion is manual digit emission via recursive `write` calls.

## See Also

- [ft_putchar_fd](ft-putchar-fd.md), [ft_putstr_fd](ft-putstr-fd.md) — sibling output functions
