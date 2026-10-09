#include "libft.h"
#include "registry.h"
#include "theft.h"
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static enum theft_trial_res	prop_set_then_compare(struct theft *t, void *arg1,
		void *arg2)
{
	size_t	count;
	size_t	size;
	char	*expected;
	char	*actual;

	(void)t;
	count = *(const size_t *)arg1;
	size = *(const size_t *)arg2;
	if (count == 0 || size == 0 || (size != 0 && count > SIZE_MAX / size))
	{
		actual = ft_calloc(count, size);
		free(actual);
		if (errno == EINVAL)
		{
			return (THEFT_TRIAL_PASS);
		}
		return (THEFT_TRIAL_SKIP);
	}
	actual = ft_calloc(count, size);
	expected = calloc(count, size);
	if (actual == NULL && expected == NULL)
	{
		return (THEFT_TRIAL_PASS);
	}
	if (actual == NULL || expected == NULL)
	{
		free(actual);
		free(expected);
		return (THEFT_TRIAL_FAIL);
	}
	if (memcmp(actual, expected, count) == 0)
	{
		free(actual);
		free(expected);
		return (THEFT_TRIAL_PASS);
	}
	free(actual);
	free(expected);
	return (THEFT_TRIAL_FAIL);
}

int	ft_calloc_test(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.prop2 = prop_set_then_compare,
		.name = __FILE__,
		.trials = 1000,
		.type_info = {theft_get_builtin_type_info(THEFT_BUILTIN_size_t),
			theft_get_builtin_type_info(THEFT_BUILTIN_size_t)},
	};
	res = theft_run(&cfg);
	if (res == THEFT_RUN_PASS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

REGISTER_TEST(1, ft_calloc_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_calloc_test());
}
#endif
