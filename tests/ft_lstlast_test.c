#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <stdint.h>
#include "test.h"

static void	noop(void *content)
{
	(void)content;
}

tstsuite("ft_lstlast") {
    tstcase("last returns the tail node") {
        int		i;
		int		val;
		t_list	*head;
		t_list	*last;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            head = NULL;
            tstexpect(ft_lstlast(head) == NULL, "ft_lstlast: empty list");
            val = rand();
            ft_lstadd_front(&head, ft_lstnew((void *)(intptr_t)val));
            tstexpect(ft_lstlast(head) == head, "ft_lstlast: one node");
            last = head;
            val = rand();
            ft_lstadd_front(&head, ft_lstnew((void *)(intptr_t)val));
            tstexpect(ft_lstlast(head) == last, "ft_lstlast: two nodes");
            val = rand();
            ft_lstadd_front(&head, ft_lstnew((void *)(intptr_t)val));
            tstexpect(ft_lstlast(head) == last, "ft_lstlast: three nodes");
            ft_lstclear(&head, noop);
        }
    }
}
