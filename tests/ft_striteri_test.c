#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <string.h>
#include "test.h"

static void	f_iter(unsigned int i, char *c)
{
	(void)i;
	*c = '?';
}

tstsuite("ft_striteri") {
    tstcase("property replaces every char with '?' in place") {
        char	*s;
        char	*s_save;
        char	*expected;
        size_t	len;
        int		i;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            s = make_rand_str();
            if (s == NULL)
                continue ;
            s_save = strdup(s);
            if (s_save == NULL) {
                free(s);
                continue ;
            }
            len = strlen(s);
            ft_striteri(s, f_iter);
            expected = calloc(1 + len, sizeof(char));
            if (expected == NULL) {
                free(s_save);
                free(s);
                continue ;
            }
            memset(expected, '?', len);
            tstexpect(strcmp(expected, s) == 0,
                "ft_striteri(%s) did not set all chars to '?'", s_save);
            free(s_save);
            free(expected);
            free(s);
        }
    }
}
