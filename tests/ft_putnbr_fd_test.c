#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "test.h"

static void	putnbr_wrapper(void *payload, int fd)
{
	ft_putnbr_fd(*(int *)payload, fd);
}

tstsuite("ft_putnbr_fd") {
    tstcase("property writes the integer text to the fd") {
        int		num;
        char	expected[32];
        size_t	len;
        int		i;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            num = (int)rand();
            snprintf(expected, sizeof(expected), "%d", num);
            len = strlen(expected);
            tstexpect(assert_fd_output(putnbr_wrapper, &num, expected, len),
                "ft_putnbr_fd(%d) wrote wrong bytes", num);
        }
    }
}
