# strnstr

> Sources: Linux Kernel API documentation, 2026-08-14
> Raw: ../../raw/string-functions/strnstr.md
> Updated: 2026-08-14

## Overview

The `strnstr()` function finds the first occurrence of a substring in a length-limited string. Unlike `strstr()`, it limits the search to a specified number of characters.

## Description

`strnstr()` finds the first occurrence of the substring `s2` in the string `s1`, but not more than `len` characters are searched. The function takes three parameters: `s1` (the string to be searched), `s2` (the string to search for), and `len` (the maximum number of characters to search). This is a GNU extension and is not part of the standard C library.

Key points:
- Finds first occurrence of `s2` in `s1`, searching at most `len` characters
- Returns a pointer to the beginning of the located substring, or NULL if not found
- GNU extension, not in standard C library
- Available in the Linux kernel API
- Similar to `strstr()` but with a length limit on the haystack
