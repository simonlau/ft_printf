# 02-strlen-wrong-var-in-format-string.md

Status: open
Type: bug
File: tests/ft_strlen_test.c:31

## Problem
The `tstexpect` in the `tstsection("Check bounds")` block references `s` (the property-test loop variable) instead of `tstcurdata` (the value actually being tested). On failure, the error message prints the wrong string, making debugging misleading.

## Fix
Change the format string/args to reference `tstcurdata` consistently:
```
tstexpect((expected = strlen(tstcurdata)) == (result = ft_strlen(tstcurdata)),
    "ft_strlen(%s) = %zu != %zu", tstcurdata, result, expected);
```
