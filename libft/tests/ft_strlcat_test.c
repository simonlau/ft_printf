#include "libft.h"
#include "registry.h"
#include "theft.h"
#include <stdio.h>
#include <string.h>
#if defined(__GLIBC__)
# include <bsd/string.h>
#endif

static enum theft_trial_res	prop_oracle(struct theft *t, void *arg1, void *arg2,
		void *arg3)
{
	char		*dst;
	char		*src;
	char		*actual;
	char		*expected;
	size_t		result;
	uint16_t	num;
	size_t		answer;
	int			dst_len;

	(void)t;
	dst = (char *)arg1;
	src = (char *)arg2;
	num = *(uint16_t *)arg3;
	dst_len = strlen(dst);
	dst_len = dst_len > 0 ? dst_len + 1 : 0;
	actual = calloc(num, sizeof(*actual));
	if (actual == NULL)
	{
		return (THEFT_TRIAL_SKIP);
	}
	snprintf(actual, num, "%s", dst);
	expected = calloc(num, sizeof(*expected));
	if (expected == NULL)
	{
		return (THEFT_TRIAL_SKIP);
	}
	snprintf(expected, num, "%s", dst);
	result = ft_strlcat(actual, src, num);
	answer = strlcat(expected, src, num);
	if (result == answer && memcmp(actual, expected, num) == 0)
	{
		free(expected);
		free(actual);
		return (THEFT_TRIAL_PASS);
	}
	free(expected);
	free(actual);
	return (THEFT_TRIAL_FAIL);
}

int	ft_strlcat_test(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.prop3 = prop_oracle,
		.name = __FILE__,
		.trials = 1000,
		.type_info = {theft_get_builtin_type_info(THEFT_BUILTIN_char_ARRAY),
			theft_get_builtin_type_info(THEFT_BUILTIN_char_ARRAY),
			theft_get_builtin_type_info(THEFT_BUILTIN_uint16_t)},
	};
	res = theft_run(&cfg);
	if (res == THEFT_RUN_PASS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

REGISTER_TEST(1, ft_strlcat_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_strlcat_test());
}
#endif
