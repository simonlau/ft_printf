#include "libft.h"
#include "registry.h"
#include "theft.h"
#include <string.h>

static enum theft_trial_res	check_substr(const char *s, unsigned int start,
		size_t len)
{
	char	*result;
	char	*expected;
	size_t	s_len;
	size_t	expected_len;

	s_len = strlen(s);
	if (start >= s_len)
		expected_len = 0;
	else
	{
		expected_len = s_len - start;
		if (len < expected_len)
			expected_len = len;
	}
	result = ft_substr(s, start, len);
	expected = malloc(expected_len + 1);
	if (expected == NULL)
	{
		free(result);
		return (THEFT_TRIAL_FAIL);
	}
	if (expected_len > 0)
		memcpy(expected, s + start, expected_len);
	expected[expected_len] = NULL_CHAR;
	if (result == NULL || strcmp(result, expected) != 0)
	{
		free(result);
		free(expected);
		return (THEFT_TRIAL_FAIL);
	}
	free(result);
	free(expected);
	return (THEFT_TRIAL_PASS);
}

static enum theft_trial_res	prop_set_then_compare(struct theft *t, void *arg1,
		void *arg2, void *arg3)
{
	const char		*s;
	unsigned int	start;

	(void)t;
	s = (const char *)arg1;
	start = *(const unsigned int *)arg2;
	start = start % (strlen(s) + 1);
	return (check_substr(s, start, *(const size_t *)arg3));
}

static enum theft_trial_res	prop_fuzz(struct theft *t, void *arg1, void *arg2,
		void *arg3)
{
	(void)t;
	return (check_substr((const char *)arg1, *(const unsigned int *)arg2,
			*(const size_t *)arg3));
}

int	ft_substr_test(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.prop3 = prop_set_then_compare,
		.name = "substr: prop_set_then_compare",
		.trials = 1000,
		.type_info = {theft_get_builtin_type_info(THEFT_BUILTIN_char_ARRAY),
			theft_get_builtin_type_info(THEFT_BUILTIN_uint32_t),
			theft_get_builtin_type_info(THEFT_BUILTIN_size_t)},
	};
	res = theft_run(&cfg);
	if (res == THEFT_RUN_FAIL)
		return (EXIT_FAILURE);
	struct theft_run_config cfgFuzz = {
		.prop3 = prop_fuzz,
		.name = "substr: prop_fuzz",
		.trials = 1000,
		.type_info = {theft_get_builtin_type_info(THEFT_BUILTIN_char_ARRAY),
			theft_get_builtin_type_info(THEFT_BUILTIN_uint32_t),
			theft_get_builtin_type_info(THEFT_BUILTIN_size_t)},
	};
	res = theft_run(&cfgFuzz);
	if (res == THEFT_RUN_FAIL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

REGISTER_TEST(1, ft_substr_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_substr_test());
}
#endif
