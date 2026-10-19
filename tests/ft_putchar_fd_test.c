#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "test.h"

static void	putchar_wrapper(void *payload, int fd)
{
	ft_putchar_fd(*(char *)payload, fd);
}

tstsuite("ft_putchar_fd") {
    tstcase("property writes exactly one byte to the fd") {
		char	c;
		int		i;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            c = (char)rand();
            tstexpect(assert_fd_output(putchar_wrapper, &c, &c, 1),
                "ft_putchar_fd(%d) did not write expected byte", c);
        }
    }
}
