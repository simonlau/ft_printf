# ft_split

> Sources: 42 school libft subject v19.3, 2026-09-28
> Raw: [libft-subject](../../raw/project-overview/libft-subject.md)
> Updated: 2026-09-28

## Overview

`ft_split` allocates memory (using `malloc(3)`) and returns an array of strings obtained by splitting `s` using the character `c` as a delimiter. Each string in the returned array is allocated independently; the array of pointers itself is also allocated dynamically. The returned array must be NULL terminated. Prototype: `char **ft_split(char const *s, char c)`.

## Parameters

- **s** — The string to be split.
- **c** — The delimiter character.

## Return value

The array of new strings resulting from the split. NULL if any allocation fails. The returned structure will be released using: 1) `free()` on each string in the array; 2) `free()` the array itself.

## Implementation

Status: **not yet implemented** — `ft_split.c` is a stub.

Planned Part 1 functions (not yet in code): [ft_substr](ft-substr.md) to extract each word, plus direct `malloc`/`free` — the subject lists both as this function's external functions.

## See Also

- [ft_substr](ft-substr.md) — planned per-word extraction step
