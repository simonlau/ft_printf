# Spec: Migrate testing framework from theft to tst

## Problem Statement

The libft project currently uses the `theft` property-based testing framework for all 43 test files under `tests/`. The `theft` library is an external dependency that must be cloned separately, adds significant boilerplate (property functions returning `THEFT_TRIAL_PASS/FAIL`, `ft_xxx_test()` wrappers returning `EXIT_SUCCESS/FAILURE`, and `REGISTER_TEST` macro registration), and complicates the build with separate compilation and linking steps. The project is migrating to `tst`, a header-only testing framework that eliminates the external library dependency, reduces boilerplate per test file, and simplifies the build to single-step compilation per test binary.

## Solution

Replace `theft` with `tst` across all 43 test files. Each test file is converted from the theft property-function pattern (`static enum theft_trial_res prop_xxx(...)` + `int ft_xxx_test(void)` + `REGISTER_TEST`) to the tst suite pattern (`tstsuite("name") { tstcase("desc") { ... } }`). The conversion preserves the same property logic and oracle comparisons, but uses `tstcheck()` assertions instead of `THEFT_TRIAL_PASS/FAIL` returns, and deterministic `srand(0)` loops instead of theft's random trial generation. The Makefile is updated to remove theft references, add tst include paths, and fix broken build/clean/run targets. The consolidated `tests` runner runs all tests binaries

## User Stories

1. As a developer, I want `make test` to build and run all per-file test binaries, so that I can verify the library compiles and passes its property tests.
2. As a developer, I want `make run-tests` to build and run each test binary with ASAN_OPTIONS set, so that memory and UB errors are caught automatically.
4. As a developer, I want `make run-all` to build and run the consolidated runner, so that I get a summary of all test results at once.
5. As a developer, I want `make clean` to remove all test binaries and coverage artifacts, so that the workspace stays tidy.
6. As a developer, I want each test file to include `"libft.h"` consistently (not `../libft.h`), so that header resolution works regardless of the build context.
7. As a developer, I want the `tst` library to be fetched via `make clone-tst`, so that the test framework dependency is set up in one command.
10. As a developer, I want the `ft_strnstr` test to preserve its custom allocator and 4-property-variant logic, so that the most complex test is not simplified during conversion.
11. As a developer, I want the fd-write tests (`putchar_fd`, `putstr_fd`, `putendl_fd`, `putnbr_fd`) to use the same pipe-oracle pattern, so that output correctness is verified against expected strings.
12. As a developer, I want the list tests to verify internal state (size, order, pointers), so that list operations are thoroughly checked.

## Implementation Decisions

- **Framework choice**: `tst` (header-only, from `https://github.com/rdentato/tst.git`) replaces `theft`. The `tst.h` header is fetched via `make clone-tst` into `tst/` directory.
- **Test structure**: Each test file uses `tstsuite("name") { tstcase("desc") { ... } }` with `tstcheck(condition, "message")` for assertions. The test body is a `for` loop of TRIALS iterations using `srand(SEED)` for deterministic random inputs.
- **Property logic preservation**: The oracle comparison logic from each theft property function is ported verbatim into the tst test body. For single-argument tests, the loop generates random inputs and compares against libc oracles. For multi-argument tests, the same input generation and comparison logic is preserved.
- **Registry**: The existing `registry.h`/`registry.c` self-registering pattern is removed.
- **Build system**: The Makefile is updated to:
  - Use `$(TEST_BINS)` consistently (not undefined `$(TESTS)`)
  - Add `$(TST_DIR)/src` to `CFLAGS` for `tst.h` discovery
  - Track `$(TST_DIR)/src/tst.h` as a dependency for test binaries
  - Enable the consolidated `all-tests` target with `-DALL_TESTS`
  - Set `ASAN_OPTIONS=allocator_may_return_null=1` for `run-tests` and `run-all`
- **Include paths**: All test files use `#include "libft.h"` (not `../libft.h`) for consistency. The Makefile passes `-I. -I$(TEST_DIR)` so both `libft.h` and `test.h` resolve correctly.
- **Test constants**: `SEED` and `TRIALS` are defined in `tests/test.h` (currently `SEED 42`, `TRIALS 2000`). Converted files use these via `#include "test.h"`.
- **Edge cases**: The `ft_strnstr` test retains its custom allocator (`hay_alloc`) with alphabet-bit configuration (1-byte {a,b} vs 8-byte full range), and runs 4 property variants (spec oracle, sweep with ab alphabet, sweep with byte alphabet, ft-vs-system diff) plus a fuzz sweep. The `ft_split` test preserves its skip-on-delimiter-found logic and 3-element array comparison.

## Testing Decisions

- **Good test criteria**: Each test verifies external behavior only — the output of `ft_*` functions against libc oracles or manually constructed expected results. No test inspects internal implementation details (e.g., pointer arithmetic, struct field access beyond what the function contract guarantees).
- **Modules tested**: All 43 `ft_*` functions are covered: character checks (isalpha, isdigit, isalnum, isascii, isprint), string/memory (strlen, memset, bzero, memcpy, memmove, strlcpy, strlcat, strchr, strrchr, strncmp, memchr, memcmp, strnstr, atoi), heap (calloc, strdup), case conversion (toupper, tolower), additional strings (substr, strjoin, strtrim, split, itoa, strmapi, striteri), fd writes (putchar_fd, putstr_fd, putendl_fd, putnbr_fd), and linked list (lstnew, lstadd_front, lstsize, lstlast, lstadd_back, lstdelone, lstclear, lstiter, lstmap).
- **Prior art**: The existing theft property tests serve as the specification for what each test should verify. The oracle comparisons (libc `isalpha`, `strchr`, `memcpy`, etc.) and manually constructed expected results (e.g., `ft_substr` expected substring, `ft_split` expected array) are the established patterns. The already-converted single-argument tests (isalpha, isdigit, isalnum, isascii, isprint, toupper, tolower, strlen, memset, bzero, memcpy, memmove, strchr, strrchr, strncmp) provide the template for the remaining conversions.

## Out of Scope

- Adding new test cases beyond what the original theft tests covered
- Improving test coverage for functions that currently have no tests
- Refactoring the library source code itself
- Adding performance benchmarks or stress tests
- Migrating the `theft` library code or preserving it as a fallback
- Changing the registry mechanism or consolidated runner architecture
- Adding non-property-based unit tests (edge case hand-written tests)

## Further Notes

- The migration is split into 7 tickets (published to `.scratch/migrate-tests-to-tst/issues/`): 01 (build infra), 02 (list ops basic), 03 (list ops advanced), 04 (string + heap), 05 (complex strnstr), 06 (fd writes), 07 (verification). Ticket 01 is the foundation; tickets 02-06 can proceed in parallel after 01; ticket 07 verifies the full suite end-to-end.
- The `tst` framework is header-only, so no library compilation or linking is needed — each test file just `#include "tst.h"` and the framework's constructor-based suite registration handles test execution.
- The `test.h` file defines `SEED` and `TRIALS` constants. Some already-converted files use `srand(0)` directly instead of `SEED` — this inconsistency should be resolved during ticket 01 (build infra) by standardizing on one approach.
- The `ft_strnstr_test.c` is the most complex file (213 lines in theft version) and may require the most careful conversion. Its custom allocator and 4-property-variant structure should be preserved rather than simplified.
