# ft_strtrim

> Sources: 42 school libft subject v19.3, 2026-09-28
> Raw: [libft-subject](../../raw/project-overview/libft-subject.md)
> Updated: 2026-09-28

## Overview

`ft_strtrim` allocates memory (using `malloc(3)`) and returns a copy of `s1` with characters from `set` removed from the beginning and the end. Prototype: `char *ft_strtrim(char const *s1, char const *set)`.

## Parameters

- **s1** — The string to be trimmed.
- **set** — The string containing the set of characters to be removed.

## Return value

The trimmed string. NULL if the allocation fails.

## Implementation

Status: **not yet implemented** — `ft_strtrim.c` is a stub.

Planned Part 1 functions (not yet in code): [strchr](../string-functions/strchr.md) to test set membership while scanning from both ends, [ft_substr](ft-substr.md) to extract the surviving middle, plus a direct `malloc` as the subject allows.

## Deviations from the subject

- The stub is declared `char *ft_strtrim(char const *s)` — it drops the `set` parameter entirely. The subject requires `char const *s1, char const *set`.

## See Also

- [ft_substr](ft-substr.md) — planned extraction step
- [strchr](../string-functions/strchr.md) — planned set-membership test
