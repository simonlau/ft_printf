/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 11:00:00 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/12 22:01:06 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h"
#include <limits.h>
#include <stdlib.h>
#include <string.h>

tstsuite("ft_printf nbr")
{
	char	out[OUT_MAX];
	char	expected[OUT_MAX];
	int		num;
	int		expected_num;
	int		tstdata[NUM_TRIALS];
	int		vals[] = {0, INT_MIN, INT_MAX, -1, 1, 9, 10, -9, -10, 99, 100, -99,
				-100, INT_MIN + 1, INT_MAX - 1};

	srand(SEED);
	tstcase("signed int")
	{
		for (int i = 0; i < NUM_TRIALS; i++)
		{
			tstdata[i] = (int)(((unsigned int)rand() << 16) ^ (unsigned int)rand());
		}
		tstsection("check int")
		{
			cap_begin();
			num = ft_printf("%i", tstcurdata);
			cap_end(out, sizeof(out));
			expected_num = snprintf(expected, sizeof(expected), "%i",
					tstcurdata);
			tstexpect(num == expected_num && strcmp(out, expected) == 0,
				"num=%d out=%s expected_num=%d expected=%s", num, out,
				expected_num, expected);
		}
	}
	tstcase("signed edges")
	{
		for (size_t i = 0; i < sizeof(vals) / sizeof(vals[0]); i++)
		{
			cap_begin();
			num = ft_printf("%d", vals[i]);
			cap_end(out, sizeof(out));
			expected_num = snprintf(expected, sizeof(expected), "%d", vals[i]);
			tstexpect(num == expected_num && strcmp(out, expected) == 0,
				"num=%d out=%s expected_num=%d expected=%s", num, out,
				expected_num, expected);
		}
	}
}
