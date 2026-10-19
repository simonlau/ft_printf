# 01-bzero-calloc-wrong-size.md

Status: open
Type: bug
File: tests/ft_bzero_test.c:24

## Problem
`expected = calloc(len, len * sizeof(*expected));` allocates `len * len` bytes instead of `len`. This is an O(n²) overallocation. The `memcmp` only checks `len` bytes so it does not cause false positives, but it is incorrect allocation arithmetic.

## Fix
`calloc(len, sizeof(*expected))` — allocate exactly `len` bytes.
