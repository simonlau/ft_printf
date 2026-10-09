#include "libft.h"
#include "registry.h"
#include "theft.h"
#include <string.h>

static enum theft_trial_res	prop_oracle(struct theft *t, void *arg1, void *arg2)
{
	const char	*s;
	int			c;
	char		*expected;
	char		*result;

	(void)t;
	s = (const char *)arg1;
	c = *(const int *)arg2;
	result = ft_strchr(s, c);
	expected = strchr(s, c);
	if (result == expected)
		return (THEFT_TRIAL_PASS);
	return (THEFT_TRIAL_FAIL);
}

int	ft_strchr_test(void)
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

REGISTER_TEST(1, ft_strchr_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_strchr_test());
}
#endif
