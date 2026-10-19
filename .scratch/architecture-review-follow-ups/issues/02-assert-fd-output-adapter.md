# 02: Add assert_fd_output fd-capture adapter to test utils

**What to build:** A shared fd-capture adapter declared in `tests/test.h` and defined in `tests/test_utils.c` that owns the pipe → write → close write → capture → drain → compare sequence internally. Accepts a `void (*fn)(void *, int fd)` wrapper plus expected bytes. Uses a fixed internal buffer. Returns `void` and reports mismatch via `tstexpect` inside. Verified by wiring all four `ft_put*_fd` tests through it.

**Blocked by:** None (can start immediately).

**Status:** ready-for-agent

- [ ] `assert_fd_output` declared in `tests/test.h`
- [ ] `assert_fd_output` defined in `tests/test_utils.c`
- [ ] Adapter owns pipe → write → close write → capture → drain → compare internally
- [ ] Accepts a `void (*fn)(void *, int fd)` wrapper plus expected bytes
- [ ] Uses a fixed internal buffer managed by the adapter
- [ ] Returns `void` and reports mismatch via `tstexpect` inside
- [ ] All four `ft_put*_fd` tests pass through the adapter under `make test` with ASan+UBSan
