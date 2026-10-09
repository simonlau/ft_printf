# ft_strmapi

> Sources: 42 school libft subject v19.3, 2026-09-28
> Raw: [libft-subject](../../raw/project-overview/libft-subject.md)
> Updated: 2026-09-28

## Overview

`ft_strmapi` applies the function `f` to each character of the string `s`, passing its index as the first argument and the character itself as the second. A new string is created (using `malloc(3)`) to store the results from the successive applications of `f`. Prototype: `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))`.

## Parameters

- **s** — The string to iterate over.
- **f** — The function to apply to each character.

## Return value

The string created from the successive applications of `f`. Returns NULL if the allocation fails.

## Implementation

Status: **not yet implemented** — `ft_strmapi.c` is a stub.

Planned Part 1 functions (not yet in code): [strlen](../string-functions/strlen.md) to size the result buffer, plus a direct `malloc` as the subject allows.

## See Also

- [ft_striteri](ft-striteri.md) — in-place counterpart that shares the callback shape
- [strlen](../string-functions/strlen.md) — planned buffer sizing
