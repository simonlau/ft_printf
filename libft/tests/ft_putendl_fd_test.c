#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "test.h"

static void	putendl_wrapper(void *payload, int fd)
{
	ft_putendl_fd((char *)payload, fd);
}

tstsuite("ft_putendl_fd") {
    tstcase("property writes string plus newline to the fd") {
        char		*str;
        char		expected[128];
        size_t		len;
        int		i;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            str = make_rand_str();
            if (str == NULL)
                continue ;
            len = strlen(str);
            if (len + 1 > sizeof(expected) - 1)
            {
                free(str);
                continue ;
            }
            memcpy(expected, str, len);
            expected[len] = '\n';
            tstexpect(assert_fd_output(putendl_wrapper, str, expected, len + 1),
                "ft_putendl_fd(%s) did not write string + newline", str);
            free(str);
        }
    }
}
