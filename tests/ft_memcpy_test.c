#include "libft.h"
#include "registry.h"
#include "theft.h"
#include <string.h>

static enum theft_trial_res	prop_oracle(struct theft *t, void *arg)
{
	char	*str;
	int		len;
	char	*expected;
	char	*actual;
	char	*result;

	(void)t;
	str = (char *)arg;
	len = strlen(str);
	actual = malloc(len * sizeof(*actual));
	expected = malloc(len * sizeof(*expected));
	memcpy(expected, str, len);
	// act
	result = ft_memcpy(actual, str, len);
	if (memcmp(actual, expected, len) == 0 && result == actual)
	{
		free(actual);
		free(expected);
		return (THEFT_TRIAL_PASS);
	}
	free(actual);
	free(expected);
	return (THEFT_TRIAL_FAIL);
}

int	ft_memcpy_test(void)
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

REGISTER_TEST(1, ft_memcpy_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_memcpy_test());
}
#endif
