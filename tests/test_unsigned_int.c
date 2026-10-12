/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unsigned_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 11:00:00 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/12 22:01:13 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h"
#include <limits.h>
#include <stdlib.h>
#include <string.h>

tstsuite("ft_printf nbr")
{
	char			out[OUT_MAX];
	char			expected[OUT_MAX];
	int				num;
	int				expected_num;
	unsigned int	tstdata[NUM_TRIALS];
	unsigned int	vals[] = {0U, 1U, 9U, 10U, 99U, 100U, INT_MAX,
			(unsigned int)INT_MAX + 1U, 3000000000U, 4000000000U, UINT_MAX - 1U,
			UINT_MAX};

	srand(SEED);
	tstcase("unsigned nbr")
	{
		for (int i = 0; i < NUM_TRIALS; i++)
		{
			tstdata[i] = ((unsigned int)rand() << 16) ^ (unsigned int)rand();
		}
		tstsection("check unsigned")
		{
			cap_begin();
			num = ft_printf("%u", tstcurdata);
			cap_end(out, sizeof(out));
			expected_num = snprintf(expected, sizeof(expected), "%u",
					tstcurdata);
			tstexpect(num == expected_num && strcmp(out, expected) == 0,
				"num=%d out=%s expected_num=%d expected=%s", num, out,
				expected_num, expected);
		}
	}
	tstcase("unsigned edges")
	{
		for (unsigned int i = 0; i < sizeof(vals) / sizeof(vals[0]); i++)
		{
			cap_begin();
			num = ft_printf("%u", vals[i]);
			cap_end(out, sizeof(out));
			expected_num = snprintf(expected, sizeof(expected), "%u", vals[i]);
			tstexpect(num == expected_num && strcmp(out, expected) == 0,
				"num=%d out=%s expected_num=%d expected=%s", num, out,
				expected_num, expected);
		}
	}
	tstcase("mixed nbr")
	{
		cap_begin();
		num = ft_printf("%d %i %u", -42, 42, UINT_MAX);
		cap_end(out, sizeof(out));
		expected_num = snprintf(expected, sizeof(expected), "%d %i %u", -42, 42,
				UINT_MAX);
		tstexpect(num == expected_num && strcmp(out, expected) == 0,
			"num=%d out=%s expected_num=%d expected=%s", num, out, expected_num,
			expected);
	}
}
