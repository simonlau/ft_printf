#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <stdint.h>
#include "test.h"

static int	g_calls;

static void	*change(void *content)
{
	g_calls++;
	return ((void *)(uintptr_t)((uintptr_t)content + 1));
}

static void	noop(void *content)
{
	(void)content;
}

tstsuite("ft_lstmap") {
    tstcase("map invokes function once per node and maps content") {
        int		i;
		t_list	*head;
		t_list	*result;
		t_list	*cur;
		t_list	*orig;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            head = make_rand_lst(3);
            g_calls = 0;
            result = ft_lstmap(head, change, noop);
            if (result != NULL)
            {
                tstexpect(g_calls == 3, "ft_lstmap: function called 3 times");
                cur = result;
                orig = head;
                while (cur != NULL && orig != NULL)
                {
                    tstexpect((uintptr_t)cur->content == (uintptr_t)orig->content + 1,
                         "ft_lstmap: mapped content is input + 1");
                    cur = cur->next;
                    orig = orig->next;
                }
                ft_lstclear(&result, noop);
            }
            ft_lstclear(&head, noop);
        }
    }

    tstcase("edge map NULL list") {
        t_list	*result;

        result = ft_lstmap(NULL, change, noop);
        tstexpect(result == NULL, "ft_lstmap: NULL list returns NULL");
    }

    tstcase("edge map NULL function") {
        t_list	*head;
        t_list	*result;

        head = make_rand_lst(3);
        if (head != NULL)
        {
            result = ft_lstmap(head, NULL, noop);
            tstexpect(result == NULL, "ft_lstmap: NULL function returns NULL");
            ft_lstclear(&head, noop);
        }
    }
}
