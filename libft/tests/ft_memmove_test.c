#include "libft.h"
#include "registry.h"
#include "theft.h"
#include <string.h>

static enum theft_trial_res	prop_oracle(struct theft *t, void *arg1, void *arg2)
{
	char	*buf;
	int		config;
	size_t	len;
	char	*expected;
	char	*actual;
	void	*result;

	(void)t;
	buf = (char *)arg1;
	config = *(const int *)arg2;
	len = strlen(buf);
	if (len == 0)
		return (THEFT_TRIAL_PASS);
	expected = strdup(buf);
	actual = strdup(buf);
	if (config < 0)
	{
		// backward overlap: dst > src (else branch)
		memmove(expected + 1, expected, len);
		result = ft_memmove(actual + 1, actual, len);
		if (result == actual + 1 && memcmp(actual, expected, len + 1) == 0)
		{
			free(expected);
			free(actual);
			return (THEFT_TRIAL_PASS);
		}
	}
	else if (config > 0)
	{
		// forward overlap: dst < src (if branch)
		memmove(expected, expected + 1, len);
		result = ft_memmove(actual, actual + 1, len);
		if (result == actual && memcmp(actual, expected, len + 1) == 0)
		{
			free(expected);
			free(actual);
			return (THEFT_TRIAL_PASS);
		}
	}
	else
	{
		// same pointer (dst == src)
		memmove(expected, expected, len);
		result = ft_memmove(actual, actual, len);
		if (result == actual && memcmp(actual, expected, len + 1) == 0)
		{
			free(expected);
			free(actual);
			return (THEFT_TRIAL_PASS);
		}
	}
	free(expected);
	free(actual);
	return (THEFT_TRIAL_FAIL);
}

int	ft_memmove_test(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.prop2 = prop_oracle,
		.name = __FILE__,
		.trials = 1000,
		.type_info = {theft_get_builtin_type_info(THEFT_BUILTIN_char_ARRAY),
			theft_get_builtin_type_info(THEFT_BUILTIN_int)},
	};
	res = theft_run(&cfg);
	if (res == THEFT_RUN_PASS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

REGISTER_TEST(1, ft_memmove_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_memmove_test());
}
#endif
