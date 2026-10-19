#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <stdint.h>
#include "test.h"

static void	noop(void *content)
{
	(void)content;
}

static int	lst_content_matches(t_list *head, int *expected, int count)
{
	int		i;
	t_list	*cur;

	i = 0;
	cur = head;
	while (i < count && cur != NULL)
	{
		if ((intptr_t)cur->content != (intptr_t)expected[i])
			return (0);
		cur = cur->next;
		i++;
	}
	return (i == count && cur == NULL);
}

tstsuite("ft_lstadd_back") {
    tstcase("add_back appends and size increments") {
        int		i;
		int		val;
		int		expected[3];
		t_list	*head;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            head = NULL;
            tstexpect(ft_lstsize(head) == 0, "ft_lstadd_back: empty list");
            val = rand();
            expected[0] = val;
            ft_lstadd_back(&head, ft_lstnew((void *)(intptr_t)val));
            tstexpect(ft_lstsize(head) == 1 && lst_content_matches(head, expected, 1),
                     "ft_lstadd_back: one node");
            val = rand();
            expected[1] = val;
            ft_lstadd_back(&head, ft_lstnew((void *)(intptr_t)val));
            tstexpect(ft_lstsize(head) == 2 && lst_content_matches(head, expected, 2),
                     "ft_lstadd_back: two nodes");
            val = rand();
            expected[2] = val;
            ft_lstadd_back(&head, ft_lstnew((void *)(intptr_t)val));
            tstexpect(ft_lstsize(head) == 3 && lst_content_matches(head, expected, 3),
                     "ft_lstadd_back: three nodes");
            ft_lstclear(&head, noop);
        }
    }
}
