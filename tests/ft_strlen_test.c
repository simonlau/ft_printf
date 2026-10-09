#include "libft.h"
#include "registry.h"
#include "theft.h"
#include <string.h>

static enum theft_trial_res	prop_oracle(struct theft *t, void *arg)
{
	const char	*c;
	size_t		result;
	size_t		expected;

	(void)t;
	c = (const char *)arg;
	result = ft_strlen(c);
	expected = strlen(c);
	if (expected == result)
		return (THEFT_TRIAL_PASS);
	return (THEFT_TRIAL_FAIL);
}

int	ft_strlen_test(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.prop1 = prop_oracle,
		.name = __FILE__,
		.trials = 1000,
		.type_info = {theft_get_builtin_type_info(THEFT_BUILTIN_char_ARRAY)},
	};
	res = theft_run(&cfg);
	if (res == THEFT_RUN_PASS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

REGISTER_TEST(1, ft_strlen_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_strlen_test());
}
#endif
