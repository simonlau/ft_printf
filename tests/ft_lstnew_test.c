#include "libft.h"
#include "registry.h"
#include "theft.h"

static enum theft_trial_res	prop_lstnew(struct theft *t, void *arg)
{
	char	*str;
	t_list	*result;

	(void)t;
	str = (char *)arg;
	result = ft_lstnew(str);
	if (result != NULL)
	{
		if (result->content != str || result->next != NULL)
		{
			return (THEFT_TRIAL_FAIL);
		}
		free(result);
		return (THEFT_TRIAL_PASS);
	}
	return (THEFT_TRIAL_PASS);
}

int	ft_lstnew_test(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.prop1 = prop_lstnew,
		.name = __FILE__,
		.trials = 1000,
		.type_info = {theft_get_builtin_type_info(THEFT_BUILTIN_char_ARRAY)},
	};
	res = theft_run(&cfg);
	if (res != THEFT_RUN_PASS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

REGISTER_TEST(1, ft_lstnew_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_lstnew_test());
}
#endif
