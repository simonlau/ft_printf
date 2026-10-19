#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <stdint.h>
#include "test.h"

tstsuite("ft_lstnew") {
    tstcase("new node holds content and NULL next") {
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
                tstexpect(result->content == content, "ft_lstnew: content mismatch");
                tstexpect(result->next == NULL, "ft_lstnew: next should be NULL");
                free(result);
            }
        }
        result = ft_lstnew(NULL);
        tstexpect(result != NULL, "ft_lstnew: NULL content returns node");
        if (result != NULL)
        {
            tstexpect(result->content == NULL, "ft_lstnew: NULL content");
            tstexpect(result->next == NULL, "ft_lstnew: NULL content next is NULL");
            free(result);
        }
    }
}
