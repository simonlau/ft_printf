# ft_strjoin

> Sources: 42 school libft subject v19.3, 2026-09-28
> Raw: [libft-subject](../../raw/project-overview/libft-subject.md)
> Updated: 2026-09-28

## Overview

`ft_strjoin` allocates memory (using `malloc(3)`) and returns a new string, which is the result of concatenating `s1` and `s2`. Prototype: `char *ft_strjoin(char const *s1, char const *s2)`.

## Parameters

- **s1** — The prefix string.
- **s2** — The suffix string.

## Return value

The new string. NULL if the allocation fails.

## Implementation

Status: **implemented** in `ft_strjoin.c`.

Built entirely on Part 1 functions: [strlen](../string-functions/strlen.md) for both input lengths, [calloc](../stdlib-functions/calloc.md) for the zeroed result buffer, then [strlcpy](../string-functions/strlcpy.md) and [strlcat](../string-functions/strlcat.md) to copy `s1` and append `s2` with truncation-safe sizes.

## See Also

- [ft_substr](ft-substr.md) — sibling allocation-based string builder
- [strlen](../string-functions/strlen.md), [calloc](../stdlib-functions/calloc.md), [strlcpy](../string-functions/strlcpy.md), [strlcat](../string-functions/strlcat.md) — Part 1 building blocks
