# 08-lstmap-no-mapped-content-verification.md

Status: open
Type: gap
File: tests/ft_lstmap_test.c

## Problem
The test asserts `g_calls == 3` (function invoked once per node) but never verifies that the mapped list's nodes carry the transformed `content`. It also never tests `lst == NULL` or `f == NULL`.

## Fix
Assert `result` nodes hold the transformed content; add `NULL` lst and `NULL` f cases.
