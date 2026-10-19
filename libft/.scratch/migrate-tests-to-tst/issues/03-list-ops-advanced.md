# 03: List ops advanced: lstadd_front, lstiter, lstmap

**What to build:** Convert 3 linked-list test files from theft to tst. `lstadd_front` verifies size progression (0→1→2→3) and order; `lstiter` counts callback invocations (expects exactly 3); `lstmap` maps over a 3-element list, preserves result structure, and clears inputs without leaking. Each needs careful conversion of property logic that inspects internal list state.

**Blocked by:** 01

**Status:** resolved

## Answer

Converted all 3 advanced linked-list test files from theft to tst (issue 03). Each uses `tstsuite`/`tstcase` with `tstexpect` assertions, `srand(SEED)` + `TRIALS` (2000) deterministic loops, random int content cast via `(void *)(intptr_t)val`, and `noop` del with `ft_lstclear` to free nodes — no heap-allocated content strings, so ASAN reports no leaks. Preserves the original theft property logic verbatim:

- `ft_lstadd_front`: size progression 0→1→2→3 after successive `ft_lstadd_front` calls.
- `ft_lstiter`: callback invocation counter (`g_calls`) must equal exactly 3 after iterating a 3-node list.
- `ft_lstmap`: map function invoked exactly 3 times over a 3-node list; result list and input list both cleared with `noop`.

- [x] `ft_lstadd_front_test.c` compiles with tst and passes
- [x] `ft_lstiter_test.c` compiles with tst and passes
- [x] `ft_lstmap_test.c` compiles with tst and passes

Verification:
- `make test`: exit 0, all tst binaries pass (3 new list suites: 0 FAIL).
- `make run-tests`: exit 0, ASAN/UBSAN clean, no leaks on the 3 new tests.
- Norminette on `tests/` is not enforced (pre-commit `files: ^[^/]+\.(c|h)$`); new files match the style of already-converted tests (e.g. `ft_lstadd_back_test.c`).