/* ************************************************************************** */
/*                                                                            */
/*   ft_isdigit_test.c                                                        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "registry.h"
#include "theft.h"
#include <ctype.h>
#include <limits.h>

static enum theft_trial_res	prop_oracle(struct theft *t, void *arg)
{
	unsigned char	c;
	int				result;
	int				expected;

	(void)t;
	c = *(const unsigned char *)arg;
	result = ft_isdigit(c);
	expected = isdigit(c);
	if ((expected == 0 && result == 0) || (expected != 0 && result == 1))
		return (THEFT_TRIAL_PASS);
	return (THEFT_TRIAL_FAIL);
}

// static enum theft_alloc_res	valid_char_alloc(struct theft *t, void *env,
// 		void **instance)
// {
// 	const uint64_t	n_uchar = (uint64_t)UCHAR_MAX + 1;
// 	int				*c;

// 	(void)env;
// 	c = malloc(sizeof(*c));
// 	if (c == NULL)
// 		return (THEFT_ALLOC_ERROR);
// 	if (theft_random_choice(t, n_uchar + 1) == n_uchar)
// 		*c = EOF;
// 	else
// 		*c = (int)theft_random_choice(t, n_uchar);
// 	*instance = c;
// 	return (THEFT_ALLOC_OK);
// }

// static struct theft_type_info	valid_char_info = {
// 	.alloc = valid_char_alloc,
// 	.free = theft_generic_free_cb,
// };

int	ft_isdigit_test(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.prop1 = prop_oracle,
		.name = __FILE__,
		.trials = 1000,
		.type_info = {theft_get_builtin_type_info(THEFT_BUILTIN_uint8_t)},
	};
	// .type_info = {&valid_char_info},
	res = theft_run(&cfg);
	if (res == THEFT_RUN_PASS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

REGISTER_TEST(1, ft_isdigit_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_isdigit_test());
}
#endif
