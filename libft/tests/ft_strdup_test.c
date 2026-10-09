#include "libft.h"
#include "registry.h"
#include "theft.h"
#include <string.h>

static enum theft_trial_res	prop_set_then_compare(struct theft *t, void *arg)
{
	const char	*s1;
	char		*expected;
	char		*actual;

	(void)t;
	s1 = (const char *)arg;
	actual = ft_strdup(s1);
	expected = strdup(s1);
	if (strcmp(actual, expected) == 0 && actual != expected)
	{
		free(actual);
		free(expected);
		return (THEFT_TRIAL_PASS);
	}
	free(actual);
	free(expected);
	return (THEFT_TRIAL_FAIL);
}

int	ft_strdup_test(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.prop1 = prop_set_then_compare,
		.name = __FILE__,
		.trials = 1000,
		.type_info = {theft_get_builtin_type_info(THEFT_BUILTIN_char_ARRAY)},
	};
	res = theft_run(&cfg);
	if (res == THEFT_RUN_PASS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

REGISTER_TEST(1, ft_strdup_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_strdup_test());
}
#endif
