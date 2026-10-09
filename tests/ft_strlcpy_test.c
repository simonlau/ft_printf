#include "libft.h"
#include "registry.h"
#include "theft.h"
#if defined(__GLIBC__)
# include <bsd/string.h>
#endif
#include <stdio.h>
#include <string.h>

static enum theft_trial_res	prop_oracle(struct theft *t, void *arg1, void *arg2)
{
	char	*str;
	char	*actual;
	char	*expected;
	size_t	len;
	size_t	result;
	size_t	num;
	size_t	answer;

	(void)t;
	str = (char *)arg1;
	num = *(size_t *)arg2;
	len = strlen(str);
	len = len > 0 ? num % (len + 1) : 0;
	actual = calloc(len + 1, sizeof(*actual));
	expected = calloc(len + 1, sizeof(*expected));
	result = ft_strlcpy(actual, str, len);
	answer = strlcpy(expected, str, len);
	if (result == answer && memcmp(actual, expected, len) == 0)
	{
		free(actual);
		free(expected);
		return (THEFT_TRIAL_PASS);
	}
	free(actual);
	free(expected);
	return (THEFT_TRIAL_FAIL);
}

int	ft_strlcpy_test(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.prop2 = prop_oracle,
		.name = __FILE__,
		.trials = 1000,
		.type_info = {theft_get_builtin_type_info(THEFT_BUILTIN_char_ARRAY),
			theft_get_builtin_type_info(THEFT_BUILTIN_size_t)},
	};
	res = theft_run(&cfg);
	if (res == THEFT_RUN_PASS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

REGISTER_TEST(1, ft_strlcpy_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_strlcpy_test());
}
#endif
