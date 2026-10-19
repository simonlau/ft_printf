#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <string.h>
#include "test.h"

tstsuite("ft_strjoin") {
    tstcase("joins two non-empty strings") {
        const char *s1 = "abc";
        const char *s2 = "def";
        char *result;

        result = ft_strjoin(s1, s2);
        tstexpect(result != NULL, "ft_strjoin NULL");
        if (result != NULL) {
            tstexpect(strcmp(result, "abcdef") == 0, "ft_strjoin content");
            free(result);
        }
    }

    tstcase("empty strings join to empty") {
        char *left;
        char *right;

        left = ft_strjoin("", "");
        right = ft_strjoin("", "");
        tstexpect(left != NULL && right != NULL, "edge case NULL");
        if (left != NULL && right != NULL) {
            tstexpect(strcmp(left, "") == 0 && strcmp(left, right) == 0,
                     "edge case failed: empty join");
            free(left);
            free(right);
        }
    }

    tstcase("edge NULL inputs") {
        char *r1;
        char *r2;
        char *r3;

        r1 = ft_strjoin(NULL, "abc");
        r2 = ft_strjoin("abc", NULL);
        r3 = ft_strjoin(NULL, NULL);
        tstexpect(r1 != NULL && strcmp(r1, "abc") == 0, "ft_strjoin NULL left");
        tstexpect(r2 != NULL && strcmp(r2, "abc") == 0, "ft_strjoin NULL right");
        tstexpect(r3 != NULL && strcmp(r3, "") == 0, "ft_strjoin NULL NULL");
        free(r1);
        free(r2);
        free(r3);
    }

    tstcase("property random strings join") {
        char	*s1;
        char	*s2;
        char	*result;
        char	*expected;
        int		i;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            s1 = make_rand_str();
            s2 = make_rand_str();
            if (s1 == NULL || s2 == NULL)
            {
                free(s1);
                free(s2);
                continue ;
            }
            result = ft_strjoin(s1, s2);
            expected = malloc(strlen(s1) + strlen(s2) + 1);
            if (result == NULL || expected == NULL)
            {
                free(result);
                free(expected);
                free(s1);
                free(s2);
                continue ;
            }
            strcpy(expected, s1);
            strcat(expected, s2);
            tstexpect(result != NULL && strcmp(result, expected) == 0
                     && result != expected,
                "ft_strjoin(%s, %s) mismatch", s1, s2);
            free(result);
            free(expected);
            free(s1);
            free(s2);
        }
    }
}
