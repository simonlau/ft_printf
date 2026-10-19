# Glossary

## Test case
A single `tstcase(...)` block inside a `tstsuite(...)`. Each case asserts via `tstexpect(...)`.

## Oracle
The reference implementation (a libc function such as `atoi` or `calloc`) that `ft_*` output is compared against.

## Property test
A test running `TRIALS` (2000) randomized iterations at a fixed `SEED` (42), comparing `ft_*` against an oracle or a self-consistency property.

## Registered test
A test function self-registered into `g_tests` through the `REGISTER_TEST` constructor, executed by the consolidated `all-tests` runner.

## Implemented flag
The `implemented` field on `struct s_test`, set from the `impl` argument of `REGISTER_TEST`; not currently used to gate execution.

## Edge case
An input at the boundary of a function's domain (NULL, empty string, overflow, delimiter-only, all-trimmed, control/high bytes) that a test may or may not exercise.

## Open edge-case questions
None resolved yet — see Resolved edge-case fixes below.

## Resolved edge-case fixes
- `ft_calloc`: zeroing now verified over the full `count * size` bytes (`tests/ft_calloc_test.c`), not just `count`.
- `ft_atoi`: added explicit overflow / `INT_MIN` / `INT_MAX` boundary cases (`tests/ft_atoi_test.c`).
- `ft_split`: added degenerate inputs (`""`, delimiter-only, single segment, uneven delimiters) (`tests/ft_split_test.c`).
- `ft_strtrim`: added all-trimmed cases requiring a freshly allocated empty (non-NULL) string (`tests/ft_strtrim_test.c`).
- `make_rand_str`: byte range extended from 32-126 to 1-255 so control and high bytes reach the string tests (`tests/test_utils.c`). Note: the `ft_is*`/`ft_to*` tests already cover the full 0-255 range via `(unsigned char)rand()` and needed no change.
- Makefile: removed the unused `all-tests`/`run-all` targets and deleted `tests/all-tests.c`, `tests/registry.c`, `tests/registry.h`; `make test` (per-file tst binaries) is now the sole runner.

## Test adapter
A shared test helper compiled into every test binary through `tests/test_utils.c` and declared in `tests/test.h`; each property test supplies only its per-iteration body (e.g. `run_trials`) or its function-under-test plus expected bytes (e.g. `assert_fd_output`).

## run_trials
The shared trial-runner adapter: owns `srand(SEED)` and the `TRIALS` loop internally; each test body runs once per iteration and asserts via `tstexpect`; bodies free their own allocations.

## assert_fd_output
The shared fd-capture adapter: owns pipe → write → close write → capture → drain → compare behind one seam; each test passes a `void (*fn)(void *payload, int fd)` wrapper plus expected bytes; returns void and reports mismatch via `tstexpect`.
