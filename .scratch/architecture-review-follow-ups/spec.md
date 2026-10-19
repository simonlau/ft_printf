## Problem Statement

The libft codebase is a sea of shallow, one-function modules. Concepts that should live behind a single seam are instead re-derived in every module that needs them, and the same edge-case gaps repeat at the public interface. From the user's perspective this shows up as:

- Property-test boilerplate — `srand(SEED)` followed by a `for (i = 0; i < TRIALS; i++)` loop plus `make_rand_str` / oracle / `tstexpect` — is copied verbatim across roughly fifteen test files. There is no single place to change the seed, the trial count, or the iteration contract, so a bug in the trial loop must be fixed in every file individually. There is no locality.
- The fd-capture sequence — pipe, write to the write end, close the write end, `capture_begin`, drain with `capture_end`, then `memcmp` against expected bytes — is duplicated across all four `ft_put*_fd` tests. A deadlock, a forgotten close, or a short-read bug would need fixing in four places.
- `ft_strtrim` dereferences a NULL `s1` through `ft_strlen(s1)` at its interface, so passing NULL input crashes. The GLOSSARY already resolves that all-trimmed inputs must yield a freshly allocated empty (non-NULL) string, but NULL input is not handled at the seam.
- `ft_atoi` accumulates `result * 10 + digit` with no overflow check and casts to `int`. The GLOSSARY claims overflow / `INT_MIN` / `INT_MAX` cases are resolved, but the code does not deliver it: behavior diverges from libc `atoi` on overflow with no clamping.

These are all interface-level problems: the implementation exists, but the seam does not protect callers or tests, and the same concept is scattered across modules instead of concentrating in one adapter.

## Solution

Introduce two shared test adapters behind the existing `tests/test.h` seam — a trial-runner adapter that owns the `SEED`/`TRIALS` loop internally, and an fd-capture adapter that owns the full pipe → write → capture → drain → compare sequence — and fix the interface gaps in `ft_strtrim` (NULL guard) and `ft_atoi` (overflow clamping), all through existing seams with no new public API surface. Each deepened module gains leverage (one interface, N call sites) and locality (fix once, fixed everywhere), and tests hit one interface instead of repeating boilerplate.

## User Stories

1. As a test author, I want a single trial-runner adapter so that I can write property tests without repeating the `srand(SEED)` / `TRIALS` loop in every test file.
2. As a test author, I want the trial-runner to own seeding internally so that changing the seed or trial count requires one edit, not fifteen.
3. As a test author, I want each trial to receive its index and a context pointer so that my per-iteration body can index trials and carry state without file-statics.
4. As a test author, I want the trial-runner to only iterate — not to assert — so that each test body remains free to call its own oracle and `tstexpect` in its own way.
5. As a test author, I want the trial-runner to return `void` so that failures are reported by the body through `tstexpect`, keeping the interface minimal.
6. As a test author, I want the trial-runner to leave allocation ownership to the body so that the helper makes no assumptions about what each test allocates.
7. As a test author, I want a single fd-capture adapter so that I can assert the output of any `ft_put*_fd` function without repeating the pipe / write / capture / drain / compare sequence.
8. As a test author, I want the fd-capture adapter to own the full sequence internally so that a capture bug is fixed in one adapter, not in four test files.
9. As a test author, I want the fd-capture adapter to accept a common function-pointer wrapper plus expected bytes so that the four differently-signed `ft_put*_fd` functions all pass through one seam.
10. As a test author, I want the fd-capture adapter to manage its own read buffer internally so that tests do not allocate or track buffer state.
11. As a test author, I want the fd-capture adapter to report mismatch via `tstexpect` internally and return `void` so that the call site is a single assertion-free statement.
12. As a library user, I want `ft_strtrim` to handle NULL `s1` without crashing so that the interface is safe at the boundary of its domain.
13. As a library user, I want `ft_strtrim` to return a freshly allocated empty (non-NULL) string on NULL input so that behavior matches the resolved all-trimmed edge case in the GLOSSARY.
14. As a library user, I want `ft_strtrim` to treat NULL `set` as "nothing to trim" so that NULL handling is symmetric between the two string arguments.
15. As a library user, I want `ft_strtrim`'s prototype to stay unchanged so that existing callers compile without modification.
16. As a library user, I want `ft_atoi` to clamp to `INT_MIN` / `INT_MAX` on overflow so that behavior matches libc `atoi` at the edge of its domain.
17. As a library user, I want `ft_atoi` to use a wider internal accumulator so that overflow is detectable before the cast to `int`.
18. As a library user, I want `ft_atoi`'s return type to stay `int` and its whitespace/sign logic unchanged so that existing callers are unaffected.
19. As a maintainer, I want both test adapters declared in `tests/test.h` and defined in `tests/test_utils.c` so that they are compiled into every test binary through the existing build rule with no Makefile changes.
20. As a maintainer, I want the GLOSSARY to define `Test adapter`, `run_trials`, and `assert_fd_output` so that the domain vocabulary matches the code.
21. As a maintainer, I want no new seams introduced so that the number of seams across the codebase stays at one per concern.
22. As a maintainer, I want the deletion test to confirm that each adapter concentrates complexity rather than scattering it.
23. As a CI operator, I want `make test` to continue to build and run every per-function binary under ASan+UBSan so that the adapters are exercised under sanitizers.
24. As a future explorer, I want the architecture review HTML report to remain in the temp directory (outside the repo) so that no review artifacts land in the codebase.

## Implementation Decisions

- Modules built or modified: the test-utils module (gains two adapters), the `ft_strtrim` module (gains a NULL guard), and the `ft_atoi` module (gains overflow clamping). The `tests/test.h` interface gains two declarations; `libft.h` is unchanged.
- Seams: all work happens through existing seams — `tests/test.h` for both test adapters, and `libft.h` for `ft_strtrim` and `ft_atoi`. No new seams are introduced; the ideal of one seam per concern is preserved.
- Architectural decision: both adapters are added to the already-shared `test_utils.c` / `test.h` pair rather than creating new files, so every test binary links them through the existing Makefile rule with no build changes.
- `run_trials` interface decision: owns `srand(SEED)` internally; body signature is `void body(int trial_index, void *ctx)`; returns `void`; the body frees its own allocations. The `SEED`/`TRIALS` contract concentrates behind one interface.
- `assert_fd_output` interface decision: owns pipe → write → close write → capture → drain → compare internally; each test passes a `void (*fn)(void *payload, int fd)` wrapper plus expected bytes; uses a fixed internal buffer; returns `void` and reports mismatch via `tstexpect` inside.
- `ft_strtrim` interface decision: NULL `s1` returns a freshly allocated empty (non-NULL) string; NULL `set` returns a copy of `s1` (nothing to trim); prototype unchanged. Matches the resolved all-trimmed edge case in the GLOSSARY.
- `ft_atoi` interface decision: accumulates in a wider internal type, clamps to `INT_MIN`/`INT_MAX` before the cast, return type stays `int`, whitespace/sign parsing unchanged. Makes the GLOSSARY's claimed overflow fix real.
- The four not-yet-grilled candidates from the architecture review (string builders onto `ft_substr`, integer-to-text hoisting) are out of scope and remain as report candidates only.

## Testing Decisions

- A good test exercises external behavior only, through the seam, never implementation details or static helpers directly.
- `run_trials` is tested through the `tests/test.h` seam: a property test supplies a per-iteration body that calls its oracle and `tstexpect`, and verifies the seed/trial contract indirectly through deterministic output at the fixed `SEED`.
- `assert_fd_output` is tested through the `tests/test.h` seam: each of the four `ft_put*_fd` tests passes its wrapper and expected bytes, and verifies output equality via `tstexpect`.
- `ft_strtrim` is tested through `libft.h`: NULL `s1`, NULL `set`, empty input, all-trimmed input, and normal trimming, each asserting the returned buffer via `tstexpect`.
- `ft_atoi` is tested through `libft.h`: overflow beyond `INT_MIN`/`INT_MAX`, boundary values, leading whitespace, and sign, comparing against the libc `atoi` oracle where defined.
- Prior art: existing per-function `tst` tests in `tests/`; the `make_rand_str`, `capture_begin`, `capture_end` helpers in `tests/test_utils.c`; the open scratch `test-review` coverage holes (e.g. strmapi index verification, memcmp length check) that a shared trial-runner makes cheap to close.

## Out of Scope

- Candidate 1 from the architecture review: collapsing `ft_split` / `ft_strtrim` / `ft_strjoin` onto `ft_substr` (Strong, not yet grilled).
- Candidate 2 from the architecture review: hoisting the integer-to-text conversion shared by `ft_itoa` and `ft_putnbr_fd` (Worth exploring, not yet grilled).
- Any change to `libft.h` prototypes or the public ABI.
- Any Makefile changes (the existing `test_utils.c` link rule is reused unchanged).
- Creation of ADRs (none of these decisions contradict an existing ADR, and no ADRs exist in this repo).

## Further Notes

- All four candidates were settled through the grilling loop (rounds Q1–Q6 per candidate) and recorded as shared understanding before this spec was written.
- The GLOSSARY was updated inline with `Test adapter`, `run_trials`, and `assert_fd_output` during the session, per the domain-modeling skill.
- The architecture-review HTML report was written to the OS temp directory (outside the repo) per the improve-codebase-architecture skill; no review artifacts land in the codebase.
- Norminette runs on root `.c`/`.h` files only (skips `tests/`); `make test` runs on every commit. Both adapters live in `tests/`, so norminette does not apply to them; `make test` exercises them under ASan+UBSan.

Status: ready-for-agent
