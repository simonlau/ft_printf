#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <ctype.h>
#include "test.h"

tstsuite("ft_isalpha") {
    tstcase("property test matches isalpha oracle") {
        int i;
        unsigned char c;
        int result;
        int expected;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            c = (unsigned char)rand();
            result = ft_isalpha(c);
            expected = isalpha(c);
            tstexpect((expected == 0 && result == 0) || (expected != 0 && result == 1),
                     "ft_isalpha(%d) = %d != %d", c, result, expected);
        }
    }
}
