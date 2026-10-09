# ft_substr

> Sources: 42 school libft subject v19.3, 2026-09-28
> Raw: [libft-subject](../../raw/project-overview/libft-subject.md)
> Updated: 2026-09-28

## Overview

`ft_substr` allocates memory (using `malloc(3)`) and returns a substring from the string `s`. The substring starts at index `start` and has a maximum length of `len`. Prototype: `char *ft_substr(char const *s, unsigned int start, size_t len)`.

## Parameters

- **s** — The original string from which to create a substring.
- **start** — The starting index of the substring within `s`.
- **len** — The maximum length of the substring.

## Return value

The substring. NULL if the allocation fails.

## Implementation

Status: **implemented** in `ft_substr.c`.

Built on the Part 1 functions [strlen](../string-functions/strlen.md) (source-length and bounds checks) and [calloc](../stdlib-functions/calloc.md) (empty-string edge case), plus a direct `malloc` for the result — the subject allows `malloc` for this function. If `start` is beyond the string length, it returns a unique empty string via `ft_calloc(1, 1)`; if `len` would run past the end, it is clamped to `s_len - start`.

## See Also

- [ft_strjoin](ft-strjoin.md) — sibling allocation-based string builder
- [strlen](../string-functions/strlen.md), [calloc](../stdlib-functions/calloc.md) — Part 1 building blocks
