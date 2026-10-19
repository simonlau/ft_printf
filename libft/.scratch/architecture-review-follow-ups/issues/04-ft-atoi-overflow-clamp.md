# 04: Clamp ft_atoi to INT_MIN / INT_MAX

**What to build:** `ft_atoi` accumulates in a wider internal type, clamps to `INT_MIN`/`INT_MAX` before the cast to `int`; return type stays `int`; whitespace/sign logic unchanged. Verified through `libft.h` against the libc `atoi` oracle on overflow, boundary, whitespace, and sign cases.

**Blocked by:** None (can start immediately).

**Status:** ready-for-agent

- [ ] `ft_atoi` accumulates in a wider internal type
- [ ] Result clamped to `INT_MIN`/`INT_MAX` before cast to `int`
- [ ] `libft.h` return type for `ft_atoi` stays `int`
- [ ] Whitespace/sign parsing logic unchanged
- [ ] Overflow, boundary, whitespace, and sign cases pass against the libc `atoi` oracle under `make test` with ASan+UBSan
