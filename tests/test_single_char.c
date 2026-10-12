/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_single_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 11:00:00 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/12 21:06:51 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h"
#include <limits.h>
#include <string.h>

tstsuite("ft_printf single char")
{
	char	out[OUT_MAX];
	char	expected[OUT_MAX];
	int		num;
	int		expected_num;
	int		tstdata[NUM_TRIALS];

	srand(SEED);
	tstcase("just percent")
	{
		cap_begin();
		num = ft_printf("%%");
		cap_end(out, sizeof(out));
		expected_num = snprintf(expected, sizeof(expected), "%%");
		tstexpect(num == expected_num && strcmp(out, expected) == 0,
			"num=%d out=%s expected_num=%d expected=%s", num, out, expected_num,
			expected);
	}
	tstcase("single char")
	{
		for (int i = 0; i < NUM_TRIALS; i++)
		{
			tstdata[i] = rand();
		}
		tstsection("check single char")
		{
			cap_begin();
			num = ft_printf("%c", tstcurdata);
			cap_end(out, sizeof(out));
			expected_num = snprintf(expected, sizeof(expected), "%c",
					tstcurdata);
			tstexpect(num == expected_num && strcmp(out, expected) == 0,
				"num=%d out=%s expected_num=%d expected=%s", num, out,
				expected_num, expected);
		}
	}
	tstcase("char A B")
	{
		for (int i = 0; i < NUM_TRIALS; i++)
		{
			tstdata[i] = rand();
		}
		tstsection("check 2 char")
		{
			tstskipif(tstcurdata == INT_MAX);
			cap_begin();
			num = ft_printf("%c%c", tstcurdata, tstcurdata + 1);
			cap_end(out, sizeof(out));
			expected_num = snprintf(expected, sizeof(expected), "%c%c",
					tstcurdata, tstcurdata + 1);
			tstexpect(num == expected_num && strcmp(out, expected) == 0,
				"num=%d out=%s expected_num=%d expected=%s", num, out,
				expected_num, expected);
		}
	}
}
