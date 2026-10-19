# 04: String + heap: strtrim, split, substr, strmapi, striteri, calloc, strdup

**What to build:** Convert 7 property-based test files from theft to tst. `strtrim` strips `set` chars from both ends of `s1` and compares against an oracle; `split` splits on delimiter `c` and verifies the resulting array; `substr` extracts a substring with start/len bounds; `strmapi` applies a per-char function and checks the result; `striteri` modifies in place and verifies; `calloc` compares zeroed allocation against libc; `strdup` compares against libc strdup. 1000 random trials each.

**Blocked by:** 01

**Status:** resolved

## Answer

Converted all 7 string + heap test files from theft to tst (issue 04). Each uses `tstsuite`/`tstcase` with `tstexpect` assertions, `srand(SEED)` + `TRIALS` (2000) deterministic loops, and `make_rand_str()` from `tests/test_utils.c` for random string inputs. Preserves the original theft property logic verbatim:

- `ft_strtrim`: trims `set + s1 + set` with `set` and compares against `ft_strtrim(s1, set)`.
- `ft_split`: splits `cc s1 cc s2 cc` on `c` and verifies `[s1, s2, NULL]` (skips when `c` appears in either string or either is empty).
- `ft_substr`: two variants — `start %= strlen(s)+1` (bounded) and raw fuzz `start/len` — compared against a hand-built expected substring.
- `ft_strmapi`: maps every char to `'?'` via a constant function, compares to an all-`'?'` expected string.
- `ft_striteri`: replaces every char with `'?'` in place, compares to all-`'?'`.
- `ft_calloc`: compares zeroed allocation against libc `calloc`, including the overflow/zero edge branch.
- `ft_strdup`: compares against libc `strdup`, checking distinct pointers and equal contents.

- [x] `ft_strtrim_test.c` compiles with tst and passes
- [x] `ft_split_test.c` compiles with tst and passes
- [x] `ft_substr_test.c` compiles with tst and passes
- [x] `ft_strmapi_test.c` compiles with tst and passes
- [x] `ft_striteri_test.c` compiles with tst and passes
- [x] `ft_calloc_test.c` compiles with tst and passes
- [x] `ft_strdup_test.c` compiles with tst and passes

Verification:
- `make test`: exit 0, all 43 tst suites pass (0 FAIL).
- `make run-tests`: exit 0, ASAN/UBSAN clean, no leaks on the 7 new tests.
- Norminette on root `*.c`/`*.h`: all OK (tests/ not enforced).