#include "libft.h"
#include "tst.h"
#include "test.h"
#include <stdlib.h>
#include <string.h>

tstsuite("ft_memmove") {
    tstcase("property test matches memmove oracle") {
        char *buf;
        int config;
        size_t len;
        char *expected;
        char *actual;
        void *result;
        
        srand(SEED);
        int i;
        for (i = 0; i < TRIALS; i++) {
            int blen = rand() % 64 + 1;
            buf = malloc(blen + 1);
            if (buf == NULL) continue;
            for (int j = 0; j < blen; j++)
                buf[j] = (char)(rand() % 95 + 32);
            buf[blen] = '\0';
            config = (rand() % 3) - 1;
            len = strlen(buf);
            if (len == 0) { free(buf); continue; }
            expected = strdup(buf);
            actual = strdup(buf);
            if (expected == NULL || actual == NULL) { free(buf); free(expected); free(actual); continue; }
            if (config < 0) {
                memmove(expected + 1, expected, len);
                result = ft_memmove(actual + 1, actual, len);
                tstexpect(result == actual + 1 && memcmp(actual, expected, len + 1) == 0,
                         "ft_memmove backward mismatch");
            } else if (config > 0) {
                memmove(expected, expected + 1, len);
                result = ft_memmove(actual, actual + 1, len);
                tstexpect(result == actual && memcmp(actual, expected, len + 1) == 0,
                         "ft_memmove forward mismatch");
            } else {
                memmove(expected, expected, len);
                result = ft_memmove(actual, actual, len);
                tstexpect(result == actual && memcmp(actual, expected, len + 1) == 0,
                         "ft_memmove same mismatch");
            }
            free(buf);
            free(expected);
            free(actual);
        }
    }
}