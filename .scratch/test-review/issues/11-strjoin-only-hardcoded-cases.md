# 11-strjoin-only-hardcoded-cases.md

Status: open
Type: gap
File: tests/ft_strjoin_test.c

## Problem
`ft_strjoin_test.c` has exactly two hardcoded cases (`"abc"+"def"`, `""+""`). It never tests `NULL` inputs (`ft_strjoin(NULL, s)`, `ft_strjoin(s, NULL)`, `ft_strjoin(NULL, NULL)`), memory independence (result is a fresh allocation), or randomized input.

## Fix
Add `NULL`-input cases and a randomized property test comparing against an oracle or self-consistency, verifying fresh allocation.
