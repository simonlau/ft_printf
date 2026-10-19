# 13-memcmp-no-len-greater-than-strlen.md

Status: open
Type: gap
File: tests/ft_memcmp_test.c

## Problem
The test computes `len = min(strlen(s1), strlen(s2))`, so `ft_memcmp` is never asked to compare bytes at or past the null terminator (e.g. `len > strlen`, embedded `\0` bytes). `ft_memcmp` must behave like `memcmp` on raw memory regardless of terminators.

## Fix
Add cases where `len` exceeds `strlen` of one/both buffers, and buffers containing embedded `\0` bytes.
