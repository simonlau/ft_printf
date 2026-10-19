#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "test.h"

static void	putstr_wrapper(void *payload, int fd)
{
	ft_putstr_fd((char *)payload, fd);
}

tstsuite("ft_putstr_fd") {
    tstcase("property writes the full string to the fd") {
        char	*s;
        size_t	len;
        int		i;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            s = make_rand_str();
            if (s == NULL)
                continue ;
            len = strlen(s);
            tstexpect(assert_fd_output(putstr_wrapper, s, s, len),
                "ft_putstr_fd(%s) wrote wrong bytes", s);
            free(s);
        }
    }
}
