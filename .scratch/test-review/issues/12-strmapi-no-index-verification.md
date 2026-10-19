# 12-strmapi-no-index-verification.md

Status: open
Type: gap
File: tests/ft_strmapi_test.c

## Problem
The callback `f_map` ignores both `i` and `c` and always returns `'?'`. The test never verifies that the `unsigned int index` argument is passed correctly (0, 1, 2, …) or that `c` is the current character. It also never tests `s == NULL` or `f == NULL`.

## Fix
Use a callback that records/transforms based on index and char; assert index sequence and char mapping; add `NULL` s / `NULL` f cases.
