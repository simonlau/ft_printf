/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2026/10/07 10:56:47 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*                                                                            */
/*   Stays RED until ft_strnstr.c actually searches.                          */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "registry.h"
#include "theft.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#if defined(__GLIBC__)
# include <bsd/string.h>
#endif

#define HAY_MAX 15

struct							s_hay_env
{
	size_t						alphabet_bits;
};

static struct s_hay_env			g_env_ab = {.alphabet_bits = 1};
static struct s_hay_env			g_env_bytes = {.alphabet_bits = 8};
static struct theft_type_info	g_hay_ab;
static struct theft_type_info	g_hay_bytes;

static char	*expected_strnstr(const char *h, const char *n, size_t len)
{
	char	*w;

	w = strstr(h, n);
	if (w != NULL && (size_t)(w - h) + strlen(n) <= len)
		return (w);
	return (NULL);
}

static enum theft_alloc_res	hay_alloc(struct theft *t, void *env,
		void **instance)
{
	struct s_hay_env	*e;
	char				*s;
	size_t				len;
	size_t				i;
	uint64_t			bits;

	e = (struct s_hay_env *)env;
	len = (size_t)theft_random_bits(t, 4);
	if (len > HAY_MAX)
		len = HAY_MAX;
	s = malloc(len + 1);
	if (s == NULL)
		return (THEFT_ALLOC_ERROR);
	i = 0;
	while (i < len)
	{
		bits = theft_random_bits(t, (uint8_t)e->alphabet_bits);
		if (e->alphabet_bits == 1)
			s[i] = (bits == 0) ? 'a' : 'b';
		else
			s[i] = (char)bits;
		i++;
	}
	s[len] = NULL_CHAR;
	*instance = s;
	return (THEFT_ALLOC_OK);
}

static int	check_lens(const char *h, const char *n)
{
	size_t	len;
	size_t	max;

	max = strlen(h) + 2;
	len = 0;
	while (len <= max)
	{
		if (ft_strnstr(h, n, len) != expected_strnstr(h, n, len))
			return (0);
		len++;
	}
	return (ft_strnstr(h, n, SIZE_MAX) == expected_strnstr(h, n, SIZE_MAX));
}

static int	check_junk(const char *h, const char *n)
{
	char	junk[20];
	size_t	hl;

	hl = strlen(h);
	if (hl > HAY_MAX)
		return (1);
	memcpy(junk, h, hl + 1);
	memset(junk + hl + 1, '#', sizeof(junk) - hl - 1);
	return (check_lens(junk, n));
}

static enum theft_trial_res	prop_sweep(struct theft *t, void *arg1, void *arg2,
		void *arg3)
{
	const char	*h;
	size_t		p;
	size_t		m;
	char		needle[HAY_MAX + 1];

	(void)t;
	h = (const char *)arg1;
	p = *(const size_t *)arg2 % (strlen(h) + 1);
	m = *(const size_t *)arg3 % (strlen(h) - p + 1);
	memcpy(needle, h + p, m);
	needle[m] = NULL_CHAR;
	if (!check_lens(h, needle) || !check_junk(h, needle))
		return (THEFT_TRIAL_FAIL);
	return (THEFT_TRIAL_PASS);
}

static enum theft_trial_res	prop_diff(struct theft *t, void *arg1, void *arg2,
		void *arg3)
{
	const char	*h;
	const char	*n;
	size_t		len;

	(void)t;
	h = (const char *)arg1;
	n = (const char *)arg2;
	len = *(const size_t *)arg3;
	if (ft_strnstr(h, n, len) != strnstr(h, n, len))
		return (THEFT_TRIAL_FAIL);
	return (THEFT_TRIAL_PASS);
}

static enum theft_trial_res	prop_spec(struct theft *t, void *arg1, void *arg2,
		void *arg3)
{
	const char	*h;
	const char	*n;
	size_t		len;

	(void)t;
	h = (const char *)arg1;
	n = (const char *)arg2;
	len = *(const size_t *)arg3;
	if (expected_strnstr(h, n, len) != strnstr(h, n, len))
		return (THEFT_TRIAL_FAIL);
	return (THEFT_TRIAL_PASS);
}

static int	run_prop(const char *name, theft_propfun3 *prop,
		const struct theft_type_info *t0, const struct theft_type_info *t1,
		const struct theft_type_info *t2)
{
	struct theft_run_config cfg = {
		.prop3 = prop,
		.name = name,
		.trials = 1000,
		.type_info = {t0, t1, t2},
		.hooks =
			{
				.trial_pre = theft_hook_first_fail_halt,
			},
	};
	return (theft_run(&cfg) == THEFT_RUN_PASS);
}

int	ft_strnstr_test(void)
{
	const struct theft_type_info	*chars;
	const struct theft_type_info	*size;
	int								ok;

	chars = theft_get_builtin_type_info(THEFT_BUILTIN_char_ARRAY);
	size = theft_get_builtin_type_info(THEFT_BUILTIN_size_t);
	theft_copy_builtin_type_info(THEFT_BUILTIN_char_ARRAY, &g_hay_ab);
	g_hay_ab.alloc = hay_alloc;
	g_hay_ab.env = &g_env_ab;
	theft_copy_builtin_type_info(THEFT_BUILTIN_char_ARRAY, &g_hay_bytes);
	g_hay_bytes.alloc = hay_alloc;
	g_hay_bytes.env = &g_env_bytes;
	ok = 1;
	ok &= run_prop("strnstr: spec vs system oracle", prop_spec, chars, chars,
			size);
	ok &= run_prop("strnstr: sweep, alphabet {a,b}", prop_sweep, &g_hay_ab,
			size, size);
	ok &= run_prop("strnstr: sweep, full-byte alphabet", prop_sweep,
			&g_hay_bytes, size, size);
	ok &= run_prop("strnstr: ft vs system oracle", prop_diff, chars, chars,
			size);
	if (!ok)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

REGISTER_TEST(1, ft_strnstr_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_strnstr_test());
}
#endif
