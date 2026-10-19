# 02: List ops basic: lstnew, lstsize, lstlast, lstadd_back, lstdelone, lstclear

**What to build:** Convert 6 linked-list test files from theft to tst. Each tests a single list function against a property oracle: `lstnew` creates a node with correct content/next; `lstsize` counts correctly after adds; `lstlast` returns the right node; `lstadd_back` appends to tail; `lstdelone` frees a node without crashing; `lstclear` empties the list. Straightforward conversion of `theft_propfunN` to `tstcase` loops over 2000 random int inputs.

**Blocked by:** 01

**Status:** resolved

## Answer

Converted all 6 linked-list test files from theft to tst (issue 02). Each uses `tstsuite`/`tstcase` with `tstexpect` assertions, `srand(SEED)` + `TRIALS` (2000) deterministic loops, random int content cast via `(void *)(intptr_t)val`, and `noop` del. No heap-allocated content strings, so nothing to free beyond the nodes themselves — ASAN reports no leaks. Preserves the original theft property logic verbatim (content/next for `lstnew`; size progression for `lstsize`/`lstadd_back`; tail-node identity for `lstlast`; no-crash del for `lstdelone`; empty+non-empty clear for `lstclear`).

- [x] `ft_lstnew_test.c` compiles with tst and passes
- [x] `ft_lstsize_test.c` compiles with tst and passes
- [x] `ft_lstlast_test.c` compiles with tst and passes
- [x] `ft_lstadd_back_test.c` compiles with tst and passes
- [x] `ft_lstdelone_test.c` compiles with tst and passes
- [x] `ft_lstclear_test.c` compiles with tst and passes

Verification:
- `make test`: exit 0, all 28 tst binaries pass (6 new list suites: 0 FAIL).
- `make run-tests`: exit 0, ASAN/UBSAN clean, no leaks on the 6 new tests.
- Norminette on `tests/` is not enforced (pre-commit `files: ^[^/]+\.(c|h)$`); new files match the style of already-converted tests (e.g. `ft_isalpha_test.c`).