#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <stdint.h>
#include "test.h"

static void	noop(void *content)
{
	(void)content;
}

tstsuite("ft_lstdelone") {
    tstcase("lstdelone frees a single node without crashing") {
        int		i;
		int		val;
		void	*content;
		t_list	*result;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            val = rand();
            content = (void *)(intptr_t)val;
            result = ft_lstnew(content);
            if (result != NULL)
            {
                tstexpect(result->content == content, "ft_lstdelone: content");
                ft_lstdelone(result, noop);
            }
        }
        ft_lstdelone(NULL, noop);
        tstexpect(1, "ft_lstdelone: NULL list does not crash");
    }
}
