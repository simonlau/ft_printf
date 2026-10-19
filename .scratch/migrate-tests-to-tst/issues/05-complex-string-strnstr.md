# 05: Complex string: ft_strnstr

**What to build:** Convert the most complex test file from theft to tst. The original uses a custom allocator generating alphabets of different sizes (1-byte {a,b} vs 8-byte full byte range), 4 property variants (spec-vs-system oracle, two sweep variants with different alphabets, ft-vs-system diff), plus fuzz sweep. Requires porting the full theft config machinery (type info, alloc hook, trial hooks) to tst's manual test loop. 1000 trials each.

**Blocked by:** 01

**Status:** resolved

## Answer

Converted `ft_strnstr_test.c` from theft to tst (issue 05), the most complex file. The custom allocator (`hay_alloc`) is ported to a manual `gen_hay()` helper that builds a haystack of random length (0–15) over either a 1-byte `{a, b}` alphabet or an 8-byte full-byte alphabet, matching the theft `alphabet_bits` configuration exactly. All 4 property variants are preserved verbatim across `TRIALS` deterministic trials:

- `prop_spec`: `expected_strnstr(h, n, len) == strnstr(h, n, len)` (oracle vs system).
- `prop_sweep` with `{a, b}` alphabet: needle sliced from the haystack, verified via `check_lens` (all lens 0..strlen+2 plus SIZE_MAX) and `check_junk` (haystack padded with `#`).
- `prop_sweep` with full-byte alphabet: same sweep over the 8-byte alphabet.
- `prop_diff`: `ft_strnstr(h, n, len) == strnstr(h, n, len)` (ft vs system oracle).

- [x] `ft_strnstr_test.c` compiles with tst
- [x] All 4 property variants pass across trials
- [x] Custom allocator logic (alphabet bits, hay allocation) preserved correctly

Verification:
- `make test`: exit 0, the strnstr suite passes (0 FAIL).
- `make run-tests`: exit 0, ASAN/UBSAN clean, no leaks.