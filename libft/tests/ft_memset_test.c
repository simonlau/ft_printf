#include "libft.h"
#include "tst.h"
#include "test.h"
#include <stdlib.h>
#include <string.h>

tstsuite("ft_memset") {
    tstcase("property test matches memset oracle") {
        char *b;
        int c;
        int len;
        char *actual;
        char *expected;
        
        srand(SEED);
        int i;
        for (i = 0; i < TRIALS; i++) {
            len = rand() % 64;
            b = malloc(len + 1);
            if (b == NULL) continue;
            for (int j = 0; j < len; j++)
                b[j] = (char)(rand() % 95 + 32);
            b[len] = '\0';
            c = rand() % 256;
            actual = strdup(b);
            expected = malloc(len * sizeof(*expected));
            if (expected == NULL) { free(b); free(actual); continue; }
            memset(expected, c, len);
            ft_memset(actual, c, len);
            tstexpect(memcmp(actual, expected, len) == 0, "ft_memset mismatch for len=%d", len);
            free(b);
            free(actual);
            free(expected);
        }
    }
}