# 04-lstadd-back-no-content-ordering.md

Status: open
Type: gap
File: tests/ft_lstadd_back_test.c

## Problem
The test only checks `ft_lstsize` increments (0→1→2→3). It never verifies that nodes are appended in order or that `content` pointers survive. An implementation that reorders or drops nodes but keeps the right size would pass.

## Fix
After each `ft_lstadd_back`, walk the list and assert each node's `content` matches the pushed value in insertion order.
