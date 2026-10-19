#include "libft.h"
#include "tst.h"
#include "test.h"
#include <stdlib.h>
#include <string.h>
#include <limits.h>

tstsuite("ft_itoa") {
    tstcase("roundtrip from ft_itoa to atoi") {
        int num;
        char *result;
        int expected;
        
        srand(SEED);
        int i;
        for (i = 0; i < TRIALS; i++) {
            num = rand() % INT_MAX - (rand() % 2);
            result = ft_itoa(num);
            if (result == NULL) continue;
            expected = atoi(result);
            tstexpect(expected == num, "ft_itoa(%d) roundtrip fail: got %d", num, expected);
            free(result);
        }
    }

    tstcase("edge extreme values") {
        struct {
            int            val;
            const char    *expected;
        } tstdata[] = {
            { 0,          "0" },
            { 1,          "1" },
            { -1,         "-1" },
            { INT_MAX,    "2147483647" },
            { INT_MIN,    "-2147483648" },
        };
        char       *result;

        tstsection("edge extreme values")
        {
            result = ft_itoa(tstcurdata.val);
            tstexpect(result != NULL && strcmp(result, tstcurdata.expected) == 0,
                "ft_itoa(%d) = %s != %s", tstcurdata.val, result ? result : "(null)", tstcurdata.expected);
            free(result);
        }
    }
}