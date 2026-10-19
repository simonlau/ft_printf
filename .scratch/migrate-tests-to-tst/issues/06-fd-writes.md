# 06: fd writes: putchar_fd, putstr_fd, putendl_fd, putnbr_fd

**What to build:** Convert 4 file-descriptor test files from theft to tst. All use the same pipe-oracle pattern: create a pipe, call the ft_*_fd function to write, read back from the pipe fd, compare to snprintf-constructed expected output. `putchar_fd` writes a single byte; `putstr_fd` writes a string; `putendl_fd` writes string + '\n'; `putnbr_fd` writes an integer. Each needs careful porting of the IO setup, read loop, and expected string construction. 1000 trials each with random int/char inputs.

**Blocked by:** 01

**Status:** resolved

## Answer

Converted all 4 file-descriptor test files from theft to tst (issue 06). Each uses the same pipe-oracle pattern: create a pipe, call the `ft_*_fd` function to write, read back from the read fd, and compare against an `snprintf`-constructed expected output. `srand(SEED)` + `TRIALS` (2000) deterministic loops with `tstexpect` assertions:

- `ft_putchar_fd`: writes a single byte; verifies exactly 1 byte read back with no extra data and byte equality.
- `ft_putstr_fd`: writes a string; verifies full length, no extra data, and byte equality.
- `ft_putendl_fd`: writes string + `'\n'`; verifies `cap = len + 1` bytes, no extra data, byte equality, and trailing newline.
- `ft_putnbr_fd`: writes an integer via `snprintf("%d", num)` expected text; verifies full length, no extra data, byte equality.

Heap-allocated read buffers are freed on every path; pipes are closed on every path, so ASAN reports no leaks or fd leaks.

- [x] `ft_putchar_fd_test.c` compiles with tst and passes
- [x] `ft_putstr_fd_test.c` compiles with tst and passes
- [x] `ft_putendl_fd_test.c` compiles with tst and passes
- [x] `ft_putnbr_fd_test.c` compiles with tst and passes

Verification:
- `make test`: exit 0, all 4 fd suites pass (0 FAIL).
- `make run-tests`: exit 0, ASAN/UBSAN clean, no leaks/fd leaks on the 4 new tests.