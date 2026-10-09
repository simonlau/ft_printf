#include "libft.h"
#include "registry.h"
#include "theft.h"
#include <stdio.h>
#include <string.h>

static enum theft_trial_res	prop_set_then_check(struct theft *t, void *arg1,
		void *arg2)
{
	const char	*s1;
	const char	*set;
	size_t		s1_len;
	size_t		set_len;
	size_t		total_len;
	char		*expected;
	char		*actual;
	char		*result;

	(void)t;
	s1 = (const char *)arg1;
	set = (const char *)arg2;
	s1_len = strlen(s1);
	set_len = strlen(set);
	total_len = 1 + s1_len + set_len * 2;
	actual = malloc(total_len * sizeof(*actual));
	if (actual == NULL)
	{
		return (THEFT_TRIAL_SKIP);
	}
	snprintf(actual, total_len, "%s%s%s", set, s1, set);
	result = ft_strtrim(actual, set);
	expected = ft_strtrim(s1, set);
	if (result == NULL && expected != NULL)
	{
		free(actual);
		free(expected);
		free(result);
		return (THEFT_TRIAL_FAIL);
	}
	if (strcmp(result, expected) == 0)
	{
		free(actual);
		free(expected);
		free(result);
		return (THEFT_TRIAL_PASS);
	}
	free(actual);
	free(expected);
	free(result);
	return (THEFT_TRIAL_FAIL);
}

int	ft_strtrim_test(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.prop2 = prop_set_then_check,
		.name = __FILE__,
		.trials = 1000,
		.type_info = {theft_get_builtin_type_info(THEFT_BUILTIN_char_ARRAY),
			theft_get_builtin_type_info(THEFT_BUILTIN_char_ARRAY)},
	};
	res = theft_run(&cfg);
	if (res == THEFT_RUN_PASS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

REGISTER_TEST(1, ft_strtrim_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_strtrim_test());
}
#endif
