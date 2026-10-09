#include "libft.h"
#include "registry.h"
#include "theft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static enum theft_trial_res	prop_oracle(struct theft *t, void *arg)
{
	char	c;
	int		fds[2];
	char	out;
	char	extra[16];
	size_t	total;
	ssize_t	r;
	size_t	more;

	(void)t;
	c = *(const char *)arg;
	if (pipe(fds) != 0)
		return (THEFT_TRIAL_SKIP);
	ft_putchar_fd(c, fds[1]);
	close(fds[1]);
	total = 0;
	while (total < 1)
	{
		r = read(fds[0], &out + total, 1 - total);
		if (r == 0)
			break ;
		if (r < 0)
		{
			close(fds[0]);
			return (THEFT_TRIAL_SKIP);
		}
		total += (size_t)r;
	}
	more = 0;
	while (1)
	{
		r = read(fds[0], extra, sizeof(extra));
		if (r == 0)
			break ;
		if (r < 0)
		{
			close(fds[0]);
			return (THEFT_TRIAL_SKIP);
		}
		more += (size_t)r;
	}
	close(fds[0]);
	if (total != 1 || more != 0)
		return (THEFT_TRIAL_FAIL);
	if (memcmp(&out, &c, 1) != EQUAL)
		return (THEFT_TRIAL_FAIL);
	return (THEFT_TRIAL_PASS);
}

int	ft_putchar_fd_test(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.prop1 = prop_oracle,
		.name = __FILE__,
		.trials = 1000,
		.type_info = {theft_get_builtin_type_info(THEFT_BUILTIN_uint8_t)},
	};
	res = theft_run(&cfg);
	if (res == THEFT_RUN_PASS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

REGISTER_TEST(1, ft_putchar_fd_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_putchar_fd_test());
}
#endif
