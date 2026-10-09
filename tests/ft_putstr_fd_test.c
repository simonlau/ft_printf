#include "libft.h"
#include "registry.h"
#include "theft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static enum theft_trial_res	prop_oracle(struct theft *t, void *arg)
{
	char	*s;
	int		fds[2];
	char	stack[4096];
	char	*out;
	size_t	len;
	size_t	total;
	ssize_t	r;
	size_t	extra;

	(void)t;
	s = (char *)arg;
	len = strlen(s);
	if (len > sizeof(stack))
		out = malloc(len);
	else
		out = stack;
	if (len != 0 && out == NULL)
		return (THEFT_TRIAL_SKIP);
	if (pipe(fds) != 0)
	{
		if (out != stack)
			free(out);
		return (THEFT_TRIAL_SKIP);
	}
	ft_putstr_fd(s, fds[1]);
	close(fds[1]);
	total = 0;
	while (total < len)
	{
		r = read(fds[0], out + total, len - total);
		if (r == 0)
			break ;
		if (r < 0)
		{
			close(fds[0]);
			if (out != stack)
				free(out);
			return (THEFT_TRIAL_SKIP);
		}
		total += (size_t)r;
	}
	extra = 0;
	while (1)
	{
		r = read(fds[0], stack, sizeof(stack));
		if (r == 0)
			break ;
		if (r < 0)
		{
			close(fds[0]);
			if (out != stack)
				free(out);
			return (THEFT_TRIAL_SKIP);
		}
		extra += (size_t)r;
	}
	close(fds[0]);
	if (total != len || extra != 0)
	{
		if (out != stack)
			free(out);
		return (THEFT_TRIAL_FAIL);
	}
	if (len > 0 && memcmp(out, s, len) != EQUAL)
	{
		if (out != stack)
			free(out);
		return (THEFT_TRIAL_FAIL);
	}
	if (out != stack)
		free(out);
	return (THEFT_TRIAL_PASS);
}

int	ft_putstr_fd_test(void)
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

REGISTER_TEST(1, ft_putstr_fd_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_putstr_fd_test());
}
#endif
