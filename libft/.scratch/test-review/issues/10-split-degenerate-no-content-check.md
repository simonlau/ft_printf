# 10-split-degenerate-no-content-check.md

Status: open
Type: gap
File: tests/ft_split_test.c

## Problem
The new "edge degenerate inputs" case (inputs `""`, `"cccc"`, `"c"`, `"a"`, `"aaaa"`, `"cac"`, `"cacccb"`) only asserts the result array is NULL-terminated. It never verifies the actual segment strings match expectations (e.g. `ft_split("a", 'c')` → `{"a", NULL}`; `ft_split("", 'c')` → `{NULL}` or `{"", NULL}` per spec).

## Fix
For each degenerate input, assert the exact expected segment array contents, not just NULL termination.
