# 01: Add run_trials trial-runner adapter to test utils

**What to build:** A shared trial-runner adapter declared in `tests/test.h` and defined in `tests/test_utils.c` that owns `srand(SEED)` and the `TRIALS` loop internally. Each test body runs once per iteration with signature `void body(int trial_index, void *ctx)`. The adapter returns `void`; failures are reported by the body through `tstexpect`. Each body frees its own allocations. Verified by a property test through the `tests/test.h` seam.

**Blocked by:** None (can start immediately).

**Status:** ready-for-agent

- [ ] `run_trials` declared in `tests/test.h`
- [ ] `run_trials` defined in `tests/test_utils.c`
- [ ] `run_trials` owns `srand(SEED)` and the `TRIALS` loop internally
- [ ] Each test body receives `(int trial_index, void *ctx)` per iteration
- [ ] Adapter returns `void`
- [ ] Property test passes through the `tests/test.h` seam under `make test` with ASan+UBSan
