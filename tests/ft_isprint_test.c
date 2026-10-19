#include "libft.h"
#include "tst.h"
#include "test.h"
#include <stdlib.h>
#include <ctype.h>

tstsuite("ft_isprint") {
    tstcase("property test matches isprint oracle") {
        int i;
        unsigned char c;
        int result;
        int expected;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            c = (unsigned char)rand();
            result = ft_isprint(c);
            expected = isprint(c);
            tstexpect((expected == 0 && result == 0) || (expected != 0 && result == 1),
                     "ft_isprint(%d) = %d != %d", c, result, expected);
        }
    }
}