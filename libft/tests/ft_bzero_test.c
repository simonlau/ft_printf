#include "libft.h"
#include "registry.h"
#include "theft.h"
#include <string.h>

static enum theft_trial_res	prop_set_then_compare(struct theft *t, void *arg)
{
	char	*s;
	int		len;
	char	*expected;
	char	*actual;

	(void)t;
	s = (char *)arg;
	len = strlen(s);
	actual = strdup(s);
	expected = calloc(len, len * sizeof(*expected));
	// bzero(expected, len);
	// act
	ft_bzero(actual, len);
	if (memcmp(actual, expected, len) == 0)
	{
		free(actual);
		free(expected);
		return (THEFT_TRIAL_PASS);
	}
	free(actual);
	free(expected);
	return (THEFT_TRIAL_FAIL);
}

int	ft_bzero_test(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.prop1 = prop_set_then_compare,
		.name = __FILE__,
		.trials = 1000,
		.type_info = {theft_get_builtin_type_info(THEFT_BUILTIN_char_ARRAY)},
	};
	res = theft_run(&cfg);
	if (res == THEFT_RUN_PASS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

REGISTER_TEST(1, ft_bzero_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_bzero_test());
}
#endif
