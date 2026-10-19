#include "libft.h"
#include "tst.h"
#include "test.h"
#include <stdlib.h>
#include <string.h>

tstsuite("ft_bzero") {
    tstcase("property test matches calloc oracle") {
        char *s;
        int len;
        char *expected;
        char *actual;
        
        srand(SEED);
        int i;
        for (i = 0; i < TRIALS; i++) {
            len = rand() % 64;
            s = malloc(len + 1);
            if (s == NULL) continue;
            for (int j = 0; j < len; j++)
                s[j] = (char)(rand() % 95 + 32);
            s[len] = '\0';
            actual = strdup(s);
            expected = calloc(len, sizeof(*expected));
            if (expected == NULL) { free(s); free(actual); continue; }
            ft_bzero(actual, len);
            tstexpect(memcmp(actual, expected, len) == 0, "ft_bzero mismatch for len=%d", len);
            free(s);
            free(actual);
            free(expected);
        }
    }
}