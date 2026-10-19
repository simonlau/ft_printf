#include "libft.h"
#include "tst.h"
#include "test.h"
#include <stdlib.h>
#include <string.h>

tstsuite("ft_strncmp") {
    tstcase("property test matches strncmp oracle") {
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
            len = (strlen(s1) + strlen(s2)) / 2;
            expected = strncmp(s1, s2, len);
            result = ft_strncmp(s1, s2, len);
            tstexpect((expected == 0 && result == 0) ||
                     (expected > 0 && result > 0) ||
                     (expected < 0 && result < 0), "ft_strncmp mismatch");
            free(s1);
            free(s2);
        }
    }
}