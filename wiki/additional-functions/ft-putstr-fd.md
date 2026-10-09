# ft_putstr_fd

> Sources: 42 school libft subject v19.3, 2026-09-28
> Raw: [libft-subject](../../raw/project-overview/libft-subject.md)
> Updated: 2026-09-28

## Overview

`ft_putstr_fd` outputs the string `s` to the specified file descriptor. Prototype: `void ft_putstr_fd(char *s, int fd)`.

## Parameters

- **s** — The string to output.
- **fd** — The file descriptor on which to write.

## Return value

None. The subject lists `write` as the only external function — a libc call, not a Part 1 reimplementation.

## Implementation

Status: **not yet implemented** — `ft_putstr_fd.c` is a stub.

Planned Part 1 functions (not yet in code): [strlen](../string-functions/strlen.md) to size the `write` call.

## Deviations from the subject

- The stub takes `const char *s`; the subject specifies `char *s`.

## See Also

- [ft_putchar_fd](ft-putchar-fd.md), [ft_putendl_fd](ft-putendl-fd.md) — sibling output functions
- [strlen](../string-functions/strlen.md) — planned write sizing
