/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 11:00:00 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/12 17:34:32 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h"
#include <string.h>

tstsuite("ft_printf ptr")
{
	char	out[OUT_MAX];
	char	expected[OUT_MAX];
	int		num;
	int		expected_num;
	int		tstdata[NUM_TRIALS];

	srand(SEED);
	tstcase("null ptr")
	{
		cap_begin();
		num = ft_printf("%p", NULL);
		cap_end(out, sizeof(out));
		expected_num = snprintf(expected, sizeof(expected), "%p", NULL);
		//! hardcode for 42 linux
		tstexpect(num == 5 && strcmp(out, "(nil)") == 0,
			"num=%d out=%s expected_num=%d expected=%s", num, out, expected_num,
			expected);
	}
	tstcase("char ptr")
	{
		for (int i = 0; i < NUM_TRIALS; i++)
		{
			tstdata[i] = rand();
		}
		tstsection("check single char")
		{
			cap_begin();
			num = ft_printf("%p", &tstcurdata);
			cap_end(out, sizeof(out));
			expected_num = snprintf(expected, sizeof(expected), "%p",
					&tstcurdata);
			tstexpect(num == expected_num && strcmp(out, expected) == 0,
				"num=%d out=%s expected_num=%d expected=%s", num, out,
				expected_num, expected);
		}
	}
}
