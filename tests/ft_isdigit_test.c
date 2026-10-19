#include "libft.h"
#include "tst.h"
#include "test.h"
#include <stdlib.h>
#include <ctype.h>

tstsuite("ft_isdigit") {
    tstcase("property test matches isdigit oracle") {
        int i;
        unsigned char c;
        int result;
        int expected;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            c = (unsigned char)rand();
            result = ft_isdigit(c);
            expected = isdigit(c);
            tstexpect((expected == 0 && result == 0) || (expected != 0 && result == 1),
                     "ft_isdigit(%d) = %d != %d", c, result, expected);
        }
    }
}