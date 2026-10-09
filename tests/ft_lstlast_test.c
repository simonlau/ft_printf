#include "libft.h"
#include "registry.h"
#include "theft.h"

static void	noop(void *content)
{
	(void)content;
	return ;
}

static enum theft_trial_res	prop_lstlast(struct theft *t, void *arg1,
		void *arg2, void *arg3)
{
	char	*a;
	char	*b;
	char	*c;
	t_list	*head;
	t_list	*last;

	(void)t;
	(void)t;
	a = (char *)arg1;
	b = (char *)arg2;
	c = (char *)arg3;
	(void)b;
	(void)c;
	head = NULL;
	if (ft_lstlast(head) != NULL)
	{
		return (THEFT_TRIAL_FAIL);
	}
	ft_lstadd_front(&head, ft_lstnew(a));
	if (ft_lstlast(head) != head)
	{
		return (THEFT_TRIAL_FAIL);
	}
	last = head;
	ft_lstadd_front(&head, ft_lstnew(b));
	if (ft_lstlast(head) != last)
	{
		return (THEFT_TRIAL_FAIL);
	}
	ft_lstadd_front(&head, ft_lstnew(c));
	if (ft_lstlast(head) != last)
	{
		return (THEFT_TRIAL_FAIL);
	}
	ft_lstclear(&head, noop);
	return (THEFT_TRIAL_PASS);
}

int	ft_lstlast_test(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.prop3 = prop_lstlast,
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

REGISTER_TEST(1, ft_lstlast_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_lstlast_test());
}
#endif
