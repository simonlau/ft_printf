#include "libft.h"
#include "registry.h"
#include "theft.h"
#include <stdio.h>
#include <string.h>

static void	free_result(char **result)
{
	int	i;

	if (result == NULL)
		return ;
	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static enum theft_trial_res	prop_set_then_check(struct theft *t, void *arg1,
		void *arg2, void *arg3)
{
	const char	*s1;
	const char	*s2;
	char		c;
	char		**result;
	size_t		len;
	char		*combined;
	const char	*expected[3];
	int			i;
	int			oneNullButNotOther;

	(void)t;
	s1 = (const char *)arg1;
	s2 = (const char *)arg2;
	c = *(const char *)arg3;
	expected[0] = s1;
	expected[1] = s2;
	expected[2] = NULL;
	if (strchr(s1, c) != NULL || strchr(s2, c) != NULL)
		return (THEFT_TRIAL_SKIP);
	if (*s1 == NULL_CHAR || *s2 == NULL_CHAR)
		return (THEFT_TRIAL_SKIP);
	len = 2 + strlen(s1) + 2 + strlen(s2) + 2 + NULL_CHAR_ALLOC;
	combined = malloc(len * sizeof(*combined));
	if (combined == NULL)
	{
		return (THEFT_TRIAL_SKIP);
	}
	snprintf(combined, len, "%c%c%s%c%c%s%c%c", c, c, s1, c, c, s2, c, c);
	result = ft_split(combined, c);
	if (result == NULL)
	{
		free(combined);
		return (THEFT_TRIAL_FAIL);
	}
	i = 0;
	while (i < 3)
	{
		oneNullButNotOther = (expected[i] == NULL) != (result[i] == NULL);
		if (oneNullButNotOther || (expected[i] != NULL && strcmp(expected[i],
					result[i]) != 0))
		{
			free_result(result);
			free(combined);
			return (THEFT_TRIAL_FAIL);
		}
		i++;
	}
	free_result(result);
	free(combined);
	return (THEFT_TRIAL_PASS);
}

int	ft_split_test(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.prop3 = prop_set_then_check,
		.name = __FILE__,
		.trials = 1000,
		.type_info = {theft_get_builtin_type_info(THEFT_BUILTIN_char_ARRAY),
			theft_get_builtin_type_info(THEFT_BUILTIN_char_ARRAY),
			theft_get_builtin_type_info(THEFT_BUILTIN_uint8_t)},
	};
	res = theft_run(&cfg);
	if (res == THEFT_RUN_PASS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

REGISTER_TEST(1, ft_split_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_split_test());
}
#endif
