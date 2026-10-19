#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <stdint.h>
#include "test.h"

static void	noop(void *content)
{
	(void)content;
}

tstsuite("ft_lstsize") {
    tstcase("size counts nodes after adds") {
        int		i;
		int		val;
		t_list	*head;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            head = NULL;
            tstexpect(ft_lstsize(head) == 0, "ft_lstsize: empty list");
            val = rand();
            head = ft_lstnew((void *)(intptr_t)val);
            tstexpect(ft_lstsize(head) == 1, "ft_lstsize: one node");
            val = rand();
            ft_lstadd_front(&head, ft_lstnew((void *)(intptr_t)val));
            tstexpect(ft_lstsize(head) == 2, "ft_lstsize: two nodes");
            val = rand();
            ft_lstadd_front(&head, ft_lstnew((void *)(intptr_t)val));
            tstexpect(ft_lstsize(head) == 3, "ft_lstsize: three nodes");
            ft_lstclear(&head, noop);
        }
    }
}
