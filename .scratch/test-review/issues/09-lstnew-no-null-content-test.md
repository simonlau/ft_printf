# 09-lstnew-no-null-content-test.md

Status: open
Type: gap
File: tests/ft_lstnew_test.c

## Problem
The test never creates a node with `content == NULL`. Per the subject, `ft_lstnew(NULL)` must produce a node with `content == NULL` and `next == NULL`.

## Fix
Add a case: `ft_lstnew(NULL)`; assert `result != NULL`, `result->content == NULL`, `result->next == NULL`.
