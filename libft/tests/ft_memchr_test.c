#include "libft.h"
#include "tst.h"
#include "test.h"
#include <stdlib.h>
#include <string.h>

tstsuite("ft_memchr") {
    tstcase("property test matches memchr oracle") {
        char *s;
        int c;
        char *expected;
        char *result;
        size_t n;
        
        srand(SEED);
        int i;
        for (i = 0; i < TRIALS; i++) {
            int slen = rand() % 64;
            s = malloc(slen + 1);
            if (s == NULL) continue;
            for (int j = 0; j < slen; j++)
                s[j] = (char)(rand() % 95 + 32);
            s[slen] = '\0';
            c = rand() % 256;
            n = strlen(s) + 1;
            result = ft_memchr(s, c, n);
            expected = memchr(s, c, n);
            tstexpect(result == expected, "ft_memchr mismatch for c=%d", c);
            free(s);
        }
    }
}