#include "libft.h"
#include "registry.h"
#include "theft.h"

static int					g_calls;

static void	*change(void *content)
{
	g_calls++;
	return (content);
}

static void	noop(void *content)
{
	(void)content;
	return ;
}

static enum theft_trial_res	prop_lstmap(struct theft *t, void *arg1, void *arg2,
		void *arg3)
{
	char	*a;
	char	*b;
	char	*c;
	t_list	*head;
	t_list	*result;

	(void)t;
	a = (char *)arg1;
	b = (char *)arg2;
	c = (char *)arg3;
	head = NULL;
	ft_lstadd_front(&head, ft_lstnew(a));
	ft_lstadd_front(&head, ft_lstnew(b));
	ft_lstadd_front(&head, ft_lstnew(c));
	g_calls = 0;
	result = ft_lstmap(head, change, noop);
	if (g_calls != 3)
	{
		ft_lstclear(&result, noop);
		ft_lstclear(&head, noop);
		return (THEFT_TRIAL_FAIL);
	}
	ft_lstclear(&result, noop);
	ft_lstclear(&head, noop);
	return (THEFT_TRIAL_PASS);
}

int	ft_lstmap_test(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.prop3 = prop_lstmap,
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

REGISTER_TEST(1, ft_lstmap_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_lstmap_test());
}
#endif
