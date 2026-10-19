#include "libft.h"
#include "tst.h"
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

tstsuite("ft_calloc") {
    tstcase("property matches libc calloc (zeroed allocation)") {
        size_t	count;
        size_t	size;
        size_t	len;
        void	*actual;
        void	*expected;
        int		i;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            count = (size_t)(rand() % 256 + 1);
            size = (size_t)(rand() % 256 + 1);
            len = count * size; /* always small: no overflow, always <= 1MB */
            actual = ft_calloc(count, size);
            expected = calloc(count, size);
            if (actual == NULL && expected == NULL) {
                /* both failed to allocate: consistent */
                continue ;
            }
            if (actual == NULL || expected == NULL) {
                tstexpect(0,
                    "ft_calloc(%zu, %zu) NULL mismatch with calloc", count, size);
                free(actual);
                free(expected);
                continue ;
            }
            tstexpect(memcmp(actual, expected, len) == 0,
                "ft_calloc(%zu, %zu) is not zeroed like calloc", count, size);
            free(actual);
            free(expected);
        }
    }
}
