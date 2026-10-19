#include "libft.h"
#include "tst.h"
#include "test.h"
#include <stdlib.h>
#include <ctype.h>

tstsuite("ft_isascii") {
    tstcase("property test matches isascii oracle") {
        int i;
        unsigned char c;
        int result;
        int expected;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            c = (unsigned char)rand();
            result = ft_isascii(c);
            expected = isascii(c);
            tstexpect((expected == 0 && result == 0) || (expected != 0 && result == 1),
                     "ft_isascii(%d) = %d != %d", c, result, expected);
        }
    }
}