#include "libft.h"
#include "registry.h"
#include "theft.h"
#include <string.h>

static enum theft_trial_res	prop_oracle(struct theft *t, void *arg1, void *arg2)
{
	char	*s1;
	char	*s2;
	size_t	len;
	int		expected;
	int		result;
	int		doubleCheck;

	(void)t;
	s1 = (char *)arg1;
	s2 = (char *)arg2;
	len = strlen(s1) < strlen(s2) ? strlen(s1) : strlen(s2);
	expected = memcmp(s1, s2, len);
	result = ft_memcmp(s1, s2, len);
	doubleCheck = ft_memcmp(s1, s1, len) == 0 && ft_memcmp(s2, s2, len) == 0;
	if (!doubleCheck)
		return (THEFT_TRIAL_FAIL);
	if (expected == 0 && result == 0)
		return (THEFT_TRIAL_PASS);
	if (expected > 0 && result > 0)
		return (THEFT_TRIAL_PASS);
	if (expected < 0 && result < 0)
		return (THEFT_TRIAL_PASS);
	return (THEFT_TRIAL_FAIL);
}

int	ft_memcmp_test(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.prop2 = prop_oracle,
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

REGISTER_TEST(1, ft_memcmp_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_memcmp_test());
}
#endif
