# 05-lstadd-front-no-content-ordering.md

Status: open
Type: gap
File: tests/ft_lstadd_front_test.c

## Problem
The test only checks `ft_lstsize` increments (0→1→2→3). It never verifies LIFO ordering — that the most recently added node is `head`. An implementation that behaves like `add_back` but tracks size would pass.

## Fix
Assert `head->content` equals the most recently pushed value after each `ft_lstadd_front`.
