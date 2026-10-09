#include "libft.h"
#include "registry.h"
#include "theft.h"
#include <string.h>

static void	noop(void *content)
{
	(void)content;
	return ;
}

static enum theft_trial_res	prop_lstclear(struct theft *t, void *arg1,
		void *arg2, void *arg3)
{
	char	*a;
	char	*b;
	char	*c;
	t_list	*head;

	(void)t;
	a = (char *)arg1;
	b = (char *)arg2;
	c = (char *)arg3;
	(void)b;
	(void)c;
	head = NULL;
	ft_lstclear(&head, noop);
	if (ft_lstsize(head) != 0)
	{
		return (THEFT_TRIAL_FAIL);
	}
	ft_lstadd_front(&head, ft_lstnew(a));
	ft_lstadd_front(&head, ft_lstnew(b));
	ft_lstadd_front(&head, ft_lstnew(c));
	ft_lstclear(&head, noop);
	if (ft_lstsize(head) != 0)
	{
		return (THEFT_TRIAL_FAIL);
	}
	return (THEFT_TRIAL_PASS);
}

int	ft_lstclear_test(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.prop3 = prop_lstclear,
		.name = __FILE__,
		.trials = 1000,
		.type_info = {theft_get_builtin_type_info(THEFT_BUILTIN_char_ARRAY),
			theft_get_builtin_type_info(THEFT_BUILTIN_char_ARRAY),
			theft_get_builtin_type_info(THEFT_BUILTIN_char_ARRAY)},
	};
	res = theft_run(&cfg);
	if (res != THEFT_RUN_PASS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

REGISTER_TEST(1, ft_lstclear_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_lstclear_test());
}
#endif
