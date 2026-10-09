# The Libft Project (Subject v19.3)

> Sources: 42 school libft subject (docs/en.subject.pdf), 2026-09-28
> Raw: [libft-subject](../../raw/project-overview/libft-subject.md)
> Updated: 2026-09-28

## Overview

Libft is the first project of the 42 C curriculum: students reimplement a set of standard C library functions under an `ft_` prefix, plus additional utility functions and a linked-list API, all packaged as a static library. The subject (version 19.3) defines the exact function inventory, the coding constraints common to all 42 projects, the README requirements, and the submission/peer-evaluation process. Its summary line: *"This project involves coding a library that will include numerous general purpose functions for your programs."*

## Project requirements

The deliverable is a static library named **libft.a**, built from `Makefile`, `libft.h`, and `ft_*.c` files placed at the repository root. The Makefile must define at least the rules `$(NAME)`, `all`, `clean`, `fclean`, and `re`, compile with `cc` using `-Wall -Wextra -Werror`, and avoid unnecessary relinking. The library must be created with `ar` — `libtool` is strictly forbidden. If bonuses are submitted, a `bonus` rule adds the `_bonus.{c/h}` files, and mandatory and bonus parts are evaluated separately.

## Technical constraints

Beyond the common 42 rules (the Norm, no unexpected quits except undefined behavior, no memory leaks, work submitted only via Git), libft adds:

- **No global variables.** Helper functions must be `static` to keep them file-scoped.
- **No unused files** may be submitted.
- **No `restrict` qualifier** in prototypes and no `-std=c99` flag, even though `restrict` is C99 — prototypes must match the originals otherwise.
- **Character classification functions** (`isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`) must return `1` on match and `0` on no match.
- **calloc quirk:** if `nmemb` or `size` is 0, return a unique pointer that can be successfully passed to `free()`.
- **glibc gap:** `strlcpy`, `strlcat`, and `bzero` are not in glibc by default; testing them against the system standard may require `<bsd/string.h>` and `-lbsd`.

## Mandatory part — Part 1: Libc functions

Reimplement these libc functions with identical prototypes and behaviors (per the man pages), differing only in the `ft_` prefix, and relying on no external functions themselves:

| Character classification | String & memory | Conversion |
|---|---|---|
| isalpha, isdigit, isalnum, isascii, isprint | strlen, memset, bzero, memcpy, memmove, strchr, strrchr, strncmp, memchr, memcmp, strnstr, strlcpy, strlcat, toupper, tolower | atoi |

`calloc` and `strdup` round out Part 1, implemented with `malloc()`.

## Mandatory part — Part 2: Additional functions

Functions not in libc, or present there in a different form:

| Function                                                  | Prototype                                                        | External     |
| --------------------------------------------------------- | ---------------------------------------------------------------- | ------------ |
| [ft_substr](../additional-functions/ft-substr.md)         | `char *ft_substr(char const *s, unsigned int start, size_t len)` | malloc       |
| [ft_strjoin](../additional-functions/ft-strjoin.md)       | `char *ft_strjoin(char const *s1, char const *s2)`               | malloc       |
| [ft_strtrim](../additional-functions/ft-strtrim.md)       | `char *ft_strtrim(char const *s1, char const *set)`              | malloc       |
| [ft_split](../additional-functions/ft-split.md)           | `char **ft_split(char const *s, char c)`                         | malloc, free |
| [ft_itoa](../additional-functions/ft-itoa.md)             | `char *ft_itoa(int n)`                                           | malloc       |
| [ft_strmapi](../additional-functions/ft-strmapi.md)       | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | malloc       |
| [ft_striteri](../additional-functions/ft-striteri.md)     | `void ft_striteri(char *s, void (*f)(unsigned int, char*))`      | None         |
| [ft_putchar_fd](../additional-functions/ft-putchar-fd.md) | `void ft_putchar_fd(char c, int fd)`                             | write        |
| [ft_putstr_fd](../additional-functions/ft-putstr-fd.md)   | `void ft_putstr_fd(char *s, int fd)`                             | write        |
| [ft_putendl_fd](../additional-functions/ft-putendl-fd.md) | `void ft_putendl_fd(char *s, int fd)`                            | write        |
| [ft_putnbr_fd](../additional-functions/ft-putnbr-fd.md)   | `void ft_putnbr_fd(int n, int fd)`                               | write        |

`ft_itoa` must handle negative numbers; `ft_split` must return a NULL-terminated array of independently allocated strings; `ft_putendl_fd` appends a newline.

## Mandatory part — Part 3: Linked list

The `t_list` struct goes in `libft.h`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

`content` holds any data type; `next` points to the next node or NULL. The API: `ft_lstnew` (malloc), `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone` (frees content via `del`, but not the next node), `ft_lstclear` (frees node + all successors, sets the list pointer to NULL), `ft_lstiter`, and `ft_lstmap` (builds a new list from successive applications of `f`, with `del` available if an allocation fails; returns NULL on allocation failure).

## README requirements

A `README.md` at the repository root must include:

- an italic first line reading *"This project has been created as part of the 42 curriculum by <login1>, <login2>..."*
- a **Description** section
- an **Instructions** section (compilation/execution)
- and a **Resources** section that also describes how AI was used — for which tasks and which parts.

A detailed description of the library itself is also required. English is recommended but the campus's main language is acceptable.

## Submission and peer-evaluation

Only the Git repository is graded, with all files at the root. Peer-evaluators may request a **brief modification of the project** during evaluation — a minor behavior change, a few lines to rewrite, an easy-to-add feature — doable in any development environment within a few minutes. It exists to verify actual understanding. Details come in the evaluation guidelines. If Deepthought is assigned to grade, it runs after peer-evaluations and stops at the first error.

## AI policy for the project

The subject dedicates a chapter to AI: apply reasoning to tasks *before* turning to AI, never ask AI for direct answers, and learn 42's global approach on AI. Exams have no internet or smartphones, so over-reliance on AI surfaces quickly; peer learning is presented as more valuable than chatting with a bot.

## See Also

Function-level documentation for the libc originals reimplemented in Part 1:
- [character-classification](../character-classification/isalpha.md) topic — isalpha, isdigit, isalnum, isascii, isprint, toupper, tolower
- [string-functions](../string-functions/strlen.md) topic — strlen, memset, memcpy, memmove, strchr, strrchr, strncmp, memchr, memcmp, strlcpy, strlcat, strnstr, bzero, strdup
- [stdlib-functions](../stdlib-functions/atoi.md) topic — atoi, calloc
