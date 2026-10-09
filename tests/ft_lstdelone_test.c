#include "libft.h"
#include "registry.h"
#include "theft.h"

static void	noop(void *content)
{
	(void)content;
	return ;
}

static enum theft_trial_res	prop_lstdelone(struct theft *t, void *arg)
{
	char	*str;
	t_list	*result;

	(void)t;
	str = (char *)arg;
	result = ft_lstnew(str);
	if (result != NULL)
	{
		ft_lstdelone(result, noop);
		return (THEFT_TRIAL_PASS);
	}
	return (THEFT_TRIAL_PASS);
}

int	ft_lstdelone_test(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.prop1 = prop_lstdelone,
		.name = __FILE__,
		.trials = 1000,
		.type_info = {theft_get_builtin_type_info(THEFT_BUILTIN_uint)},
	};
	res = theft_run(&cfg);
	if (res != THEFT_RUN_PASS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

REGISTER_TEST(1, ft_lstdelone_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_lstdelone_test());
}
#endif
