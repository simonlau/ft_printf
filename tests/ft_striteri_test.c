#include "libft.h"
#include "registry.h"
#include "theft.h"
#include <string.h>

static void	f(unsigned int i, char *c)
{
	(void)i;
	*c = '?';
}

static enum theft_trial_res	prop_set_then_check(struct theft *t, void *arg1)
{
	char	*s;
	char	*expected;

	(void)t;
	s = (char *)arg1;
	ft_striteri(s, f);
	expected = calloc(1 + strlen(s), sizeof(char));
	memset(expected, '?', strlen(s));
	if (strcmp(expected, s) == 0)
	{
		free(expected);
		return (THEFT_TRIAL_PASS);
	}
	free(expected);
	return (THEFT_TRIAL_FAIL);
}

int	ft_striteri_test(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.prop1 = prop_set_then_check,
		.name = __FILE__,
		.trials = 1000,
		.type_info = {theft_get_builtin_type_info(THEFT_BUILTIN_char_ARRAY)},
	};
	res = theft_run(&cfg);
	if (res == THEFT_RUN_PASS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

REGISTER_TEST(1, ft_striteri_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_striteri_test());
}
#endif
