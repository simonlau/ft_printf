#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <string.h>
#include "test.h"

tstsuite("ft_strtrim") {
    tstcase("property set+s1+set matches ft_strtrim(s1,set) oracle") {
        char	*s1;
        char	*set;
        char	*actual;
        char	*result;
        char	*expected;
		size_t	total_len;
		int		i;
		int		match;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            s1 = make_rand_str();
            set = make_rand_str();
            if (s1 == NULL || set == NULL)
            {
                free(s1);
                free(set);
                continue ;
            }
            total_len = 1 + strlen(s1) + 2 * strlen(set);
            actual = malloc(total_len);
            if (actual == NULL)
            {
                free(s1);
                free(set);
                continue ;
            }
            snprintf(actual, total_len, "%s%s%s", set, s1, set);
            result = ft_strtrim(actual, set);
            expected = ft_strtrim(s1, set);
            if (result == NULL && expected == NULL)
                match = 1;
            else if (result == NULL || expected == NULL)
                match = 0;
            else
                match = (strcmp(result, expected) == 0);
            tstexpect(match,
                "ft_strtrim(%s%s%s,%s) != ft_strtrim(%s,%s)",
                set, s1, set, set, s1, set);
            free(actual);
            free(result);
            free(expected);
            free(s1);
            free(set);
        }
    }

    tstcase("edge all-trimmed returns fresh empty string, not NULL") {
        struct {
            const char    *s;
            const char    *set;
        } tstdata[] = {
            { "",       "" },
            { "   ",    " " },
            { "\t\n",   " \t\n" },
            { "abba",   "ab" },
            { "xxxyxx", "xy" },
        };
        char        *result;

        tstsection("edge all-trimmed returns fresh empty string, not NULL")
        {
            result = ft_strtrim(tstcurdata.s, tstcurdata.set);
            tstexpect(result != NULL && result[0] == '\0',
                "ft_strtrim(\"%s\", \"%s\") must return fresh empty string, got %p",
                tstcurdata.s, tstcurdata.set, (void *)result);
            free(result);
        }
    }

    tstcase("edge NULL s1 returns fresh empty string, not NULL") {
        char    *result;

        result = ft_strtrim(NULL, "abc");
        tstexpect(result != NULL && result[0] == '\0',
            "ft_strtrim(NULL, \"abc\") must return fresh empty string, got %p",
            (void *)result);
        free(result);
    }

    tstcase("edge NULL set returns copy of s1") {
        char    *result;
        const char *s1 = "hello";

        result = ft_strtrim(s1, NULL);
        tstexpect(result != NULL && strcmp(result, s1) == 0,
            "ft_strtrim(\"%s\", NULL) must return copy of s1, got %p",
            s1, (void *)result);
        free(result);
    }
}
