#include "libft.h"
#include "registry.h"
#include "theft.h"
#include <stdlib.h>
#include <string.h>

static enum theft_trial_res	prop_set_then_compare(struct theft *t, void *arg1,
		void *arg2)
{
	int		c;
	char	*b;
	int		len;
	char	*actual;
	char	*expected;

	(void)t;
	b = (char *)arg1;
	c = *(const int *)arg2;
	len = strlen(b);
	actual = strdup(b);
	expected = malloc(len * sizeof(*expected));
	memset(expected, c, len);
	// act
	ft_memset(actual, c, len);
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

int	ft_memset_test(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.prop2 = prop_set_then_compare,
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

REGISTER_TEST(1, ft_memset_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_memset_test());
}
#endif
