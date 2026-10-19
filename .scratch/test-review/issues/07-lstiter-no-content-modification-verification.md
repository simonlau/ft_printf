# 07-lstiter-no-content-modification-verification.md

Status: open
Type: gap
File: tests/ft_lstiter_test.c

## Problem
The callback `change` only increments a global counter (`g_calls++`) and does not modify `*content`. The test asserts the callback was invoked 3 times but never verifies that `ft_lstiter` actually passes each node's `content` to the callback or that the callback can mutate content.

## Fix
Make `change` set `*c = 'X'` (or record the pointer values), then assert each node's content was mutated / each distinct content pointer was visited exactly once.
