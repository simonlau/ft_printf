#include "libft.h"
#include "registry.h"
#include "theft.h"
#include <stdlib.h>
#include <string.h>

static enum theft_trial_res	prop_oracle(struct theft *t, void *arg1)
{
	int		num;
	char	*result;
	int		expected;

	(void)t;
	num = *(const int *)arg1;
	result = ft_itoa(num);
	expected = atoi(result);
	if (expected == num)
	{
		free(result);
		return (THEFT_TRIAL_PASS);
	}
	free(result);
	return (THEFT_TRIAL_FAIL);
}

int	ft_itoa_test(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.prop1 = prop_oracle,
		.name = __FILE__,
		.trials = 1000,
		.type_info = {theft_get_builtin_type_info(THEFT_BUILTIN_int)},
	};
	res = theft_run(&cfg);
	if (res == THEFT_RUN_PASS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

REGISTER_TEST(1, ft_itoa_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_itoa_test());
}
#endif
