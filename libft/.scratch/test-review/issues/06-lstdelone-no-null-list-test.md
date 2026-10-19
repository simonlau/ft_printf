# 06-lstdelone-no-null-list-test.md

Status: open
Type: gap
File: tests/ft_lstdelone_test.c

## Problem
The test never calls `ft_lstdelone(NULL, del)`. A robust implementation must handle a `NULL` list node without crashing (it is a no-op per the subject).

## Fix
Add `ft_lstdelone(NULL, noop);` and assert it does not crash.
