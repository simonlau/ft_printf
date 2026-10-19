#include "libft.h"
#include "tst.h"
#include "test.h"
#include <stdlib.h>
#include <string.h>

tstsuite("ft_memcmp") {
    tstcase("property test matches memcmp oracle") {
        char *s1;
        char *s2;
        size_t len;
        int expected;
        int result;
        
        srand(SEED);
        int i;
        for (i = 0; i < TRIALS; i++) {
            int slen1 = rand() % 64;
            int slen2 = rand() % 64;
            s1 = malloc(slen1 + 1);
            s2 = malloc(slen2 + 1);
            if (s1 == NULL || s2 == NULL) { free(s1); free(s2); continue; }
            for (int j = 0; j < slen1; j++)
                s1[j] = (char)(rand() % 95 + 32);
            s1[slen1] = '\0';
            for (int j = 0; j < slen2; j++)
                s2[j] = (char)(rand() % 95 + 32);
            s2[slen2] = '\0';
            len = strlen(s1) < strlen(s2) ? strlen(s1) : strlen(s2);
            expected = memcmp(s1, s2, len);
            result = ft_memcmp(s1, s2, len);
            tstexpect((expected == 0 && result == 0) ||
                     (expected > 0 && result > 0) ||
                     (expected < 0 && result < 0), "ft_memcmp mismatch");
            free(s1);
            free(s2);
        }
    }

    tstcase("edge memcmp beyond strlen and embedded NUL") {
        unsigned char	*s1;
        unsigned char	*s2;
        size_t			len;
        int				expected;
        int				result;
        int				i;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            len = (size_t)(rand() % 64 + 1);
            s1 = malloc(len);
            s2 = malloc(len);
            if (s1 == NULL || s2 == NULL) { free(s1); free(s2); continue; }
            for (size_t j = 0; j < len; j++)
            {
                s1[j] = (unsigned char)rand();
                s2[j] = (unsigned char)rand();
            }
            /* force embedded NULs sometimes */
            if (len > 2) { s1[len / 2] = '\0'; s2[len / 2] = '\0'; }
            expected = memcmp(s1, s2, len);
            result = ft_memcmp(s1, s2, len);
            tstexpect((expected == 0 && result == 0) ||
                     (expected > 0 && result > 0) ||
                     (expected < 0 && result < 0), "ft_memcmp beyond strlen mismatch");
            free(s1);
            free(s2);
        }
    }
}