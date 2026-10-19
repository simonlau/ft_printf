#include "libft.h"
#include "tst.h"
#include "test.h"
#include <stdlib.h>
#include <ctype.h>

tstsuite("ft_toupper") {
    tstcase("property test matches toupper oracle") {
        int i;
        unsigned char c;
        int result;
        int expected;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            c = (unsigned char)rand();
            result = ft_toupper(c);
            expected = toupper(c);
            tstexpect(result == expected, "ft_toupper(%d) = %d != %d", c, result, expected);
        }
    }
}