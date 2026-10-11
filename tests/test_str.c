/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 11:00:00 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/11 20:23:12 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h"
#include <string.h>

tstsuite("ft_printf str")
{
	char	out[OUT_MAX];
	char	expected[OUT_MAX];
	int		num;
	int		expected_num;
	int		tstdata[NUM_TRIALS];
	char	str[2];
	char	*null_str;

	srand(SEED);
	tstcase("null")
	{
		null_str = NULL;
		cap_begin();
		num = ft_printf("%s", null_str);
		cap_end(out, sizeof(out));
		expected_num = snprintf(expected, sizeof(expected), "%s", null_str);
		tstexpect(num == expected_num && strcmp(out, expected) == 0,
			"num=%d out=%s expected_num=%d expected=%s", num, out, expected_num,
			expected);
	}
	tstcase("empty")
	{
		str[0] = '\0';
		cap_begin();
		num = ft_printf("%s", str);
		cap_end(out, sizeof(out));
		expected_num = snprintf(expected, sizeof(expected), "%s", str);
		tstexpect(num == expected_num && strcmp(out, expected) == 0,
			"num=%d out=%s expected_num=%d expected=%s", num, out, expected_num,
			expected);
	}
	tstcase("normal str")
	{
		for (int i = 0; i < NUM_TRIALS; i++)
		{
			tstdata[i] = rand();
		}
		tstsection("single char str")
		{
			str[0] = tstcurdata;
			str[1] = '\0';
			cap_begin();
			num = ft_printf("%s", str);
			cap_end(out, sizeof(out));
			expected_num = snprintf(expected, sizeof(expected), "%s", str);
			tstexpect(num == expected_num && strcmp(out, expected) == 0,
				"num=%d out=%s expected_num=%d expected=%s", num, out,
				expected_num, expected);
		}
	}
}
