/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:31:31 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/11 21:06:47 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h"

tstsuite("ft_printf format str only")
{
	char	out[OUT_MAX];
	char	expected[OUT_MAX];
	int		num;
	int		expected_num;
	char	*tstdata[] = {"", "hello", "world"};

	tstcase("test null format str")
	{
		cap_begin();
		num = ft_printf(NULL);
		cap_end(out, sizeof(out));
		tstexpect(num == 0 && strcmp(out, "") == 0, "ret=%d out=%s", num, out);
	}
	tstcase("test str values")
	{
		tstsection("plain str")
		{
			cap_begin();
			num = ft_printf(tstcurdata);
			cap_end(out, sizeof(out));
			expected_num = snprintf(expected, sizeof(expected), "%s",
					tstcurdata);
			tstexpect(num == expected_num && strcmp(out, expected) == 0,
				"num=%d out=%s expected_num=%d expected=%s", num, out,
				expected_num, expected);
		}
	}
}
