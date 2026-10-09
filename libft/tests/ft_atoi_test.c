#include "libft.h"
#include "registry.h"
#include "theft.h"
#include <stdio.h>
#include <stdlib.h>

static enum theft_trial_res	prop_oracle(struct theft *t, void *arg1, void *arg2)
{
	int				num;
	unsigned int	n;
	char			buf[256];
	int				result;
	int				expected;
	char			*sign;

	(void)t;
	num = *(const int *)arg1;
	n = *(const unsigned int *)arg2;
	if (n % 3 == 0)
	{
		sign = "+";
	}
	else if (n % 3 == 1)
	{
		sign = "-";
	}
	else
	{
		sign = "";
	}
	snprintf(buf, sizeof(buf), "%*s%s%d", n % 20, "", sign, num);
	result = ft_atoi(buf);
	expected = atoi(buf);
	if (expected == result)
		return (THEFT_TRIAL_PASS);
	return (THEFT_TRIAL_FAIL);
}

static enum theft_trial_res	prop_oracle_fuzz(struct theft *t, void *arg)
{
	char	*str;

	(void)t;
	str = (char *)arg;
	ft_atoi(str);
	return (THEFT_TRIAL_PASS);
}

int	ft_atoi_test(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.prop2 = prop_oracle,
		.name = __FILE__,
		.trials = 1000,
		.type_info = {theft_get_builtin_type_info(THEFT_BUILTIN_int),
			theft_get_builtin_type_info(THEFT_BUILTIN_uint)},
	};
	res = theft_run(&cfg);
	if (res == THEFT_RUN_FAIL)
		return (EXIT_FAILURE);
	struct theft_run_config cfg_fuzz = {
		.prop1 = prop_oracle_fuzz,
		.name = __FILE__,
		.trials = 1000,
		.type_info = {theft_get_builtin_type_info(THEFT_BUILTIN_char_ARRAY)},
	};
	res = theft_run(&cfg_fuzz);
	return (EXIT_SUCCESS);
}

REGISTER_TEST(1, ft_atoi_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_atoi_test());
}
#endif
