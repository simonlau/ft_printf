# ft_striteri

> Sources: 42 school libft subject v19.3, 2026-09-28
> Raw: [libft-subject](../../raw/project-overview/libft-subject.md)
> Updated: 2026-09-28

## Overview

`ft_striteri` applies the function `f` to each character of the string passed as argument, passing its index as the first argument. Each character is passed by address to `f` so it can be modified if necessary. Prototype: `void ft_striteri(char *s, void (*f)(unsigned int, char*))`.

## Parameters

- **s** — The string to iterate over.
- **f** — The function to apply to each character.

## Return value

None. The subject lists no external functions — the transformation happens in place.

## Implementation

Status: **not yet implemented** — `ft_striteri.c` is a stub.

Planned Part 1 functions (not yet in code): none — the function allocates nothing and modifies `s` in place through the callback.

## See Also

- [ft_strmapi](ft-strmapi.md) — allocating counterpart that shares the callback shape
