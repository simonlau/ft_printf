# 03-itoa-missing-extreme-values.md

Status: open
Type: gap
File: tests/ft_itoa_test.c

## Problem
The property test generates `num = rand() % INT_MAX - (rand() % 2)`, capping inputs at `INT_MAX - 1`. Boundary values `INT_MIN`, `INT_MAX`, and `0` are never exercised. These are the most likely to expose sign-handling and overflow bugs in `ft_itoa`.

## Fix
Add an edge case covering `INT_MIN`, `INT_MAX`, `0`, `-1`, `1`.
