#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <string.h>
#include "test.h"

tstsuite("ft_substr") {
    tstcase("prop set then compare: start modulo strlen(s)+1") {
        char	*s;
        unsigned int	start;
        size_t		len;
        char		*result;
        char		*expected;
        size_t		s_len;
        size_t		expected_len;
        int		i;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            s = make_rand_str();
            if (s == NULL)
                continue ;
            start = (unsigned int)rand();
            start = start % (strlen(s) + 1);
            len = (size_t)rand();
            s_len = strlen(s);
            if (start >= s_len)
                expected_len = 0;
            else {
                expected_len = s_len - start;
                if (len < expected_len)
                    expected_len = len;
            }
            result = ft_substr(s, start, len);
            expected = malloc(expected_len + 1);
            if (expected == NULL) {
                free(result);
                free(s);
                continue ;
            }
            if (expected_len > 0)
                memcpy(expected, s + start, expected_len);
            expected[expected_len] = NULL_CHAR;
            tstexpect(result != NULL && strcmp(result, expected) == 0,
                "ft_substr(%s, %u, %zu) = %s != %s",
                s, start, len,
                result ? result : "(null)", expected);
            free(result);
            free(expected);
            free(s);
        }
    }
    tstcase("prop fuzz: raw start/len") {
        char	*s;
        unsigned int	start;
        size_t		len;
        char		*result;
        char		*expected;
        size_t		s_len;
        size_t		expected_len;
        int		i;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            s = make_rand_str();
            if (s == NULL)
                continue ;
            start = (unsigned int)rand();
            len = (size_t)rand();
            s_len = strlen(s);
            if (start >= s_len)
                expected_len = 0;
            else {
                expected_len = s_len - start;
                if (len < expected_len)
                    expected_len = len;
            }
            result = ft_substr(s, start, len);
            expected = malloc(expected_len + 1);
            if (expected == NULL) {
                free(result);
                free(s);
                continue ;
            }
            if (expected_len > 0)
                memcpy(expected, s + start, expected_len);
            expected[expected_len] = NULL_CHAR;
            tstexpect(result != NULL && strcmp(result, expected) == 0,
                "ft_substr(%s, %u, %zu) = %s != %s",
                s, start, len,
                result ? result : "(null)", expected);
            free(result);
            free(expected);
            free(s);
        }
    }
}
