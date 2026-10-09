# Knowledge Base Index

## additional-functions

Part 2 of the libft subject: functions not in libc, or present there in a different form — string builders, splitters, converters, and file-descriptor output.

| Article | Summary | Updated |
|---------|---------|---------|
| [ft_substr](additional-functions/ft-substr.md) | Allocates and returns a substring of s starting at index start, max length len — implemented on ft_strlen/ft_calloc | 2026-09-28 |
| [ft_strjoin](additional-functions/ft-strjoin.md) | Allocates and returns the concatenation of s1 and s2 — implemented on ft_strlen/ft_calloc/ft_strlcpy/ft_strlcat | 2026-09-28 |
| [ft_strtrim](additional-functions/ft-strtrim.md) | Allocates a copy of s1 with set characters removed from both ends — stub, planned on ft_strchr/ft_substr | 2026-09-28 |
| [ft_split](additional-functions/ft-split.md) | Allocates a NULL-terminated array of strings split on delimiter c — stub, planned on ft_substr | 2026-09-28 |
| [ft_itoa](additional-functions/ft-itoa.md) | Allocates a string representing an integer, negatives included — implemented on malloc with recursive digit count | 2026-10-05 |
| [ft_strmapi](additional-functions/ft-strmapi.md) | Allocates a string from applying f to each character with its index — stub | 2026-09-28 |
| [ft_striteri](additional-functions/ft-striteri.md) | Applies f in place to each character with its index — stub | 2026-09-28 |
| [ft_putchar_fd](additional-functions/ft-putchar-fd.md) | Writes a character to a file descriptor — stub | 2026-09-28 |
| [ft_putstr_fd](additional-functions/ft-putstr-fd.md) | Writes a string to a file descriptor — stub | 2026-09-28 |
| [ft_putendl_fd](additional-functions/ft-putendl-fd.md) | Writes a string plus newline to a file descriptor — stub | 2026-09-28 |
| [ft_putnbr_fd](additional-functions/ft-putnbr-fd.md) | Writes an integer to a file descriptor — stub | 2026-09-28 |

## project-overview

The libft project itself — the 42 subject specification: requirements, constraints, function inventory, and evaluation rules.

| Article | Summary | Updated |
|---------|---------|---------|
| [The Libft Project (Subject v19.3)](project-overview/libft-project.md) | The 42 libft subject: build libft.a from ft_ reimplementations of libc functions, plus additional and linked-list APIs, under strict Norm and Makefile rules | 2026-09-28 |

## character-classification

Functions that test character classes such as digits, whitespace, and alphabetic characters from <ctype.h>.

| Article | Summary | Updated |
|---------|---------|---------|
| [isdigit](character-classification/isdigit.md) | The isdigit() function tests whether a given character is a decimal digit (0-9) | 2026-08-14 |
| [isspace](character-classification/isspace.md) | The isspace() function tests whether a given character is a white-space character | 2026-08-14 |
| [isalpha](character-classification/isalpha.md) | The isalpha() function tests whether a given character is an alphabetic character | 2026-08-14 |
| [isalnum](character-classification/isalnum.md) | The isalnum() function tests whether a given character is an alphanumeric character | 2026-08-14 |
| [isascii](character-classification/isascii.md) | The isascii() function tests whether a given character is a 7-bit US-ASCII character | 2026-08-14 |
| [isprint](character-classification/isprint.md) | The isprint() function tests whether a given character is a printable character | 2026-08-14 |
| [toupper](character-classification/toupper.md) | The toupper() function transliterates lowercase to uppercase | 2026-08-14 |
| [tolower](character-classification/tolower.md) | The tolower() function transliterates uppercase to lowercase | 2026-08-14 |

## string-functions

Standard C library string manipulation functions from <string.h>.

| Article | Summary | Updated |
|---------|---------|---------|
| [strlen](string-functions/strlen.md) | The strlen() function calculates the length of a string excluding the terminating null byte | 2026-08-14 |
| [memset](string-functions/memset.md) | The memset() function fills memory with a constant byte | 2026-08-14 |
| [memcpy](string-functions/memcpy.md) | The memcpy() function copies memory (no overlap allowed) | 2026-08-14 |
| [memmove](string-functions/memmove.md) | The memmove() function copies memory (overlap allowed) | 2026-08-14 |
| [memchr](string-functions/memchr.md) | The memchr() function scans memory for a character | 2026-08-14 |
| [memcmp](string-functions/memcmp.md) | The memcmp() function compares memory areas | 2026-08-14 |
| [bzero](string-functions/bzero.md) | The bzero() function zeroes a byte array (legacy) | 2026-08-14 |
| [strlcpy](string-functions/strlcpy.md) | The strlcpy() function copies a string with truncation detection | 2026-08-14 |
| [strlcat](string-functions/strlcat.md) | The strlcat() function concatenates a string with truncation detection | 2026-08-14 |
| [strchr](string-functions/strchr.md) | The strchr() function finds the first occurrence of a character in a string | 2026-08-14 |
| [strrchr](string-functions/strrchr.md) | The strrchr() function finds the last occurrence of a character in a string | 2026-08-14 |
| [strncmp](string-functions/strncmp.md) | The strncmp() function compares two strings up to n bytes | 2026-08-14 |
| [strnstr](string-functions/strnstr.md) | The strnstr() function finds a substring in a length-limited string | 2026-08-14 |
| [strdup](string-functions/strdup.md) | The strdup() function duplicates a string using malloc | 2026-08-14 |

## stdlib-functions

Standard C library functions from <stdlib.h> for memory allocation and numeric conversion.

| Article | Summary | Updated |
|---------|---------|---------|
| [atoi](stdlib-functions/atoi.md) | The atoi() function converts a string to an integer | 2026-08-14 |
| [calloc](stdlib-functions/calloc.md) | The calloc() function allocates zeroed memory for an array | 2026-08-14 |