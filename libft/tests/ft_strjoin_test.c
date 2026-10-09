#include "libft.h"
#include "registry.h"
#include "theft.h"
#include <string.h>

static enum theft_trial_res	prop_checklen(struct theft *t, void *arg1,
		void *arg2)
{
	const char	*s1;
	const char	*s2;
	char		*result;
	char		*another;

	(void)t;
	s1 = (const char *)arg1;
	s2 = (const char *)arg2;
	result = ft_strjoin(s1, s2);
	if (result == NULL)
	{
		return (THEFT_TRIAL_FAIL);
	}
	if (strlen(result) != strlen(s1) + strlen(s2))
	{
		free(result);
		return (THEFT_TRIAL_FAIL);
	}
	another = ft_strjoin(s2, s1);
	if (strlen(result) != strlen(another))
	{
		free(result);
		free(another);
		return (THEFT_TRIAL_FAIL);
	}
	free(result);
	free(another);
	return (THEFT_TRIAL_PASS);
}
static enum theft_trial_res	prop_checkEmpty(struct theft *t, void *arg1)
{
	const char	*s1;
	char		*leftEmpty;
	char		*rightEmpty;

	(void)t;
	s1 = (const char *)arg1;
	leftEmpty = ft_strjoin("", s1);
	rightEmpty = ft_strjoin(s1, "");
	if (leftEmpty == NULL || rightEmpty == NULL)
	{
		free(leftEmpty);
		free(rightEmpty);
		return (THEFT_TRIAL_FAIL);
	}
	if (strlen(s1) != strlen(leftEmpty)
		|| strlen(leftEmpty) != strlen(rightEmpty))
	{
		free(leftEmpty);
		free(rightEmpty);
		return (THEFT_TRIAL_FAIL);
	}
	if (strcmp(s1, leftEmpty) != 0 || strcmp(leftEmpty, rightEmpty) != 0)
	{
		free(leftEmpty);
		free(rightEmpty);
		return (THEFT_TRIAL_FAIL);
	}
	free(leftEmpty);
	free(rightEmpty);
	return (THEFT_TRIAL_PASS);
}

int	ft_strjoin_test(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.prop2 = prop_checklen,
		.name = "strjoin: prop_prop_checklen",
		.trials = 1000,
		.type_info = {theft_get_builtin_type_info(THEFT_BUILTIN_char_ARRAY),
			theft_get_builtin_type_info(THEFT_BUILTIN_char_ARRAY)},
	};
	res = theft_run(&cfg);
	if (res == THEFT_RUN_FAIL)
		return (EXIT_FAILURE);
	struct theft_run_config cfg_empty = {
		.prop1 = prop_checkEmpty,
		.name = "strjoin: prop_prop_checkEmpty",
		.trials = 1000,
		.type_info = {theft_get_builtin_type_info(THEFT_BUILTIN_char_ARRAY)},
	};
	res = theft_run(&cfg_empty);
	if (res == THEFT_RUN_FAIL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

REGISTER_TEST(1, ft_strjoin_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_strjoin_test());
}
#endif
