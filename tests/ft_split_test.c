#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <string.h>
#include "test.h"

static void	free_result(char **result)
{
	int	i;

	if (result == NULL)
		return ;
	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

tstsuite("ft_split") {
    tstcase("property cc s1 cc s2 cc splits into [s1, s2, NULL]") {
        char	*s1;
        char	*s2;
        char	c;
        char	**result;
        char	*combined;
        size_t	len;
        int		i;
        int		ok;

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
            if (*s1 == '\0' || *s2 == '\0')
            {
                free(s1);
                free(s2);
                continue ;
            }
            c = (unsigned char)rand();
            if (strchr(s1, c) != NULL || strchr(s2, c) != NULL)
            {
                free(s1);
                free(s2);
                continue ;
            }
            len = 6 + strlen(s1) + strlen(s2) + 1;
            combined = malloc(len);
            if (combined == NULL)
            {
                free(s1);
                free(s2);
                continue ;
            }
            snprintf(combined, len, "%c%c%s%c%c%s%c%c",
                     c, c, s1, c, c, s2, c, c);
            result = ft_split(combined, c);
            ok = 1;
            if (result == NULL)
                ok = 0;
            else if (strcmp(result[0], s1) != 0
                     || strcmp(result[1], s2) != 0
                     || result[2] != NULL)
                ok = 0;
            tstexpect(ok,
                "ft_split(%c%c%s%c%c%s%c%c, %c) != {%s, %s, NULL}",
                c, c, s1, c, c, s2, c, c, c, s1, s2);
            if (result != NULL)
                free_result(result);
            free(combined);
            free(s1);
            free(s2);
        }
    }

    tstcase("edge degenerate inputs") {
        const char	*inputs[] = {
            "",            /* empty string -> {NULL} */
            "cccc",        /* delimiter only -> {NULL} */
            "c",           /* single delimiter -> {NULL} */
            "a",           /* single segment, no delimiter -> {"a", NULL} */
            "aaaa",        /* single segment, no delimiter (multi) -> {"aaaa", NULL} */
            "cac",         /* segment surrounded -> {"a", NULL} */
            "cacccb",      /* two segments, uneven delimiters -> {"a", "b", NULL} */
        };
        const char	*expected[][3] = {
            { NULL },
            { NULL },
            { NULL },
            { "a", NULL },
            { "aaaa", NULL },
            { "a", NULL },
            { "a", "b", NULL },
        };
        char	c = 'c';
        size_t	n = sizeof(inputs) / sizeof(inputs[0]);

        for (size_t i = 0; i < n; i++) {
            char	**result = ft_split(inputs[i], c);
            int		seg_count = 0;
            int		ok = 1;

            if (result != NULL)
                while (result[seg_count] != NULL)
                    seg_count++;
            if (result == NULL)
                ok = 0;
            else if (result[seg_count] != NULL)
                ok = 0;
            else
            {
                for (int j = 0; expected[i][j] != NULL; j++)
                {
                    if (result[j] == NULL || strcmp(result[j], expected[i][j]) != 0)
                    {
                        ok = 0;
                        break ;
                    }
                }
                if (expected[i][0] == NULL && seg_count > 0)
                    ok = 0;
            }
            tstexpect(ok,
                "ft_split(\"%s\", 'c') = %p not as expected (%d segments)", inputs[i], (void *)result, seg_count);
            if (result != NULL)
                free_result(result);
        }
    }
}
