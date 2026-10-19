#include "libft.h"
#include "tst.h"
#include "test.h"
#include <stdlib.h>
#include <ctype.h>

tstsuite("ft_isalnum") {
    tstcase("property test matches isalnum oracle") {
        int i;
        unsigned char c;
        int result;
        int expected;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            c = (unsigned char)rand();
            result = ft_isalnum(c);
            expected = isalnum(c);
            tstexpect((expected == 0 && result == 0) || (expected != 0 && result == 1),
                     "ft_isalnum(%d) = %d != %d", c, result, expected);
        }
    }
}