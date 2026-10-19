#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <string.h>
#include "test.h"

tstsuite("ft_strdup") {
    tstcase("property matches libc strdup") {
        char	*s;
        char	*actual;
        char	*expected;
        int		i;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            s = make_rand_str();
            if (s == NULL)
                continue ;
            actual = ft_strdup(s);
            expected = strdup(s);
            tstexpect(actual != NULL && expected != NULL
                      && strcmp(actual, expected) == 0
                      && actual != expected,
                "ft_strdup(%s) != strdup(%s)", s, s);
            free(actual);
            free(expected);
            free(s);
        }
    }
}
