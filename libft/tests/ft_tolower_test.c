#include "libft.h"
#include "tst.h"
#include "test.h"
#include <stdlib.h>
#include <ctype.h>

tstsuite("ft_tolower") {
    tstcase("property test matches tolower oracle") {
        int i;
        unsigned char c;
        int result;
        int expected;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            c = (unsigned char)rand();
            result = ft_tolower(c);
            expected = tolower(c);
            tstexpect(result == expected, "ft_tolower(%d) = %d != %d", c, result, expected);
        }
    }
}