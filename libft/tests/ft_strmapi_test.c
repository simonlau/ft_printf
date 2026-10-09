#include "libft.h"
#include "registry.h"
#include "theft.h"
#include <stdlib.h>
#include <string.h>

static char	f(unsigned int i, char c)
{
	(void)i;
	(void)c;
	return ('?');
}

static enum theft_trial_res	prop_set_then_check(struct theft *t, void *arg1)
{
	const char	*s;
	char		*result;
	char		*expected;

	(void)t;
	s = (const char *)arg1;
	result = ft_strmapi(s, f);
	expected = calloc(1 + strlen(s), sizeof(char));
	memset(expected, '?', strlen(s));
	if (strcmp(expected, result) == 0)
	{
		free(result);
		free(expected);
		return (THEFT_TRIAL_PASS);
	}
	free(result);
	free(expected);
	return (THEFT_TRIAL_FAIL);
}
int	ft_strmapi_test(void)
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

REGISTER_TEST(1, ft_strmapi_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_strmapi_test());
}
#endif
