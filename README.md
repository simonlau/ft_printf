_This project has been created as part of the 42 curriculum by choolau_

## Description

Goal: build `libft.a`, your own C utility library, by reimplementing standard libc behavior from scratch (same prototypes/man behavior, `ft_` prefix) plus higher-level helpers you will reuse in later 42 assignments. Source: `raw/project-overview/libft-subject.md` (subject v19.3).

### Overview

Reimplements standard libc behavior from scratch (same prototypes and man-page
behavior, `ft_` prefix) plus higher-level helpers for later 42 assignments.
Subject: `raw/project-overview/libft-subject.md` (v19.3).

#### Part 1 — Libc functions

- Character checks (return `1` on match, `0` otherwise):
  `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- Strings and memory:
  `ft_strlen`, `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`,
  `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`,
  `ft_memchr`, `ft_memcmp`, `ft_strnstr`, `ft_atoi`
- Heap (via `malloc`):
  `ft_calloc` (zero-size returns a unique freeable pointer), `ft_strdup`
- Case conversion:
  `ft_toupper`, `ft_tolower`

#### Part 2 — Additional functions

- `ft_substr` — substring from `start` with max length `len`
- `ft_strjoin` — concatenate `s1` and `s2`
- `ft_strtrim` — copy of `s1` stripped of `set` chars at both ends
- `ft_split` — split on delimiter `c`; NULL-terminated array, no empty
  strings; free each string, then the array
- `ft_itoa` — integer to string, handles negatives
- `ft_strmapi` / `ft_striteri` — apply `f` per character (new string vs in place)
- `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` — `write`
  to a file descriptor

#### Part 3 — Linked list

Uses:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

- `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`,
  `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

#### Constraints

- C only, Norm clean, no globals, `static` helpers only
- `libft.a` built with `ar` at the repo root
- No crashes on defined behavior; all heap memory freed

## Instructions

Build the library:

```sh
make            # build libft.a
```

Housekeeping and reporting:

```sh
make clean     # remove objects, deps, test binaries, coverage artifacts
make fclean    # clean + remove libft.a
make re        # fclean + all
```

### Extra Instructions

Per-function property tests (each `tests/ft_*_test.c` builds to `./ft_*_test` with ASan+UBSan):

```sh
make clone-theft   # one-time: fetch theft test dependency
make test          # build all per-function test binaries
make run-tests     # build + run each test binary (ASAN_OPTIONS=allocator_may_return_null=1)
./ft_split_test    # run a single test binary
```

Consolidated runner:

```sh
make all-tests   # build ./all-tests from all tests/*.c (defines ALL_TESTS)
make run-all     # build + run ./all-tests
```

Housekeeping and reporting:

```sh
make coverage  # run-tests + gcov reports into coverage/
make wipe      # fclean + remove docs tests raw wiki skills-lock.json (destructive)
```

## Resources

Refer to [wiki](wiki/index.md)

C Property Based Testing Library - [Theft](https://github.com/silentbicycle/theft)

### Ai Usage

- Generate the files and tests files with placeholder methods
- Implement the registry for testing with `Makefile` modifications
- `ft_memmove` needed help to generate forward and backwards overlapping test cases
- `ft_strnstr` needed help to use double pointers to find overlapping needle
- `ft_calloc_test` ASAN_OPTIONS in `Makefile`
