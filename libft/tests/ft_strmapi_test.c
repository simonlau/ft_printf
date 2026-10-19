#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <string.h>
#include "test.h"

static char	f_map(unsigned int i, char c)
{
	(void)c;
	return ((char)('A' + (i % 26)));
}

tstsuite("ft_strmapi") {
    tstcase("property maps every char based on index") {
        char	*s;
        char	*result;
        char	*expected;
        size_t	len;
        int		i;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            s = make_rand_str();
            if (s == NULL)
                continue ;
            len = strlen(s);
            result = ft_strmapi(s, f_map);
            expected = malloc(len + 1);
            if (result == NULL || expected == NULL) {
                free(result);
                free(expected);
                free(s);
                continue ;
            }
            for (size_t j = 0; j < len; j++)
                expected[j] = (char)('A' + (j % 26));
            expected[len] = '\0';
            tstexpect(result != NULL && strcmp(expected, result) == 0,
                "ft_strmapi(%s) != index-based map", s);
            free(result);
            free(expected);
            free(s);
        }
    }

    tstcase("edge NULL string") {
        char	*result;

        result = ft_strmapi(NULL, f_map);
        tstexpect(result != NULL && result[0] == '\0',
            "ft_strmapi(NULL, f) returns valid empty string");
        free(result);
    }
}
