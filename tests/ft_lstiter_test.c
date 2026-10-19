#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <stdint.h>
#include "test.h"

static int		g_calls;

static void	change(void *content)
{
	*(int *)content = 42;
	g_calls++;
}

static void	del_int(void *content)
{
	free(content);
}

tstsuite("ft_lstiter") {
    tstcase("iter invokes callback once per node and mutates content") {
        int		i;
		t_list	*head;
		t_list	*cur;
		int		*val;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            head = NULL;
            for (int j = 0; j < 3; j++)
            {
                val = malloc(sizeof(int));
                if (val == NULL)
                    break ;
                *val = j;
                ft_lstadd_back(&head, ft_lstnew(val));
            }
            g_calls = 0;
            ft_lstiter(head, change);
            tstexpect(g_calls == 3, "ft_lstiter: callback called 3 times");
            cur = head;
            while (cur != NULL)
            {
                tstexpect(*(int *)cur->content == 42, "ft_lstiter: content mutated");
                cur = cur->next;
            }
            ft_lstclear(&head, del_int);
        }
    }
}
