# 03: Guard ft_strtrim against NULL input

**What to build:** `ft_strtrim` returns a freshly allocated empty (non-NULL) string on NULL `s1`, returns a copy of `s1` on NULL `set`, with the prototype unchanged in `libft.h`. Verified through `libft.h` with NULL `s1`, NULL `set`, empty, all-trimmed, and normal-trimming cases.

**Blocked by:** None (can start immediately).

**Status:** ready-for-agent

- [ ] NULL `s1` returns a freshly allocated empty (non-NULL) string
- [ ] NULL `set` returns a copy of `s1` (nothing to trim)
- [ ] `libft.h` prototype for `ft_strtrim` unchanged
- [ ] NULL `s1`, NULL `set`, empty, all-trimmed, and normal-trimming cases pass under `make test` with ASan+UBSan
