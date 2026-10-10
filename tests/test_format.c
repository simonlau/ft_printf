/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:31:31 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/10 15:30:18 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h"

tstsuite("ft_printf format str only")
{
	char	out[OUT_MAX];
	char	expected[OUT_MAX];
	int		num;
	char	format[] = "hello";
	int		expected_num;

	tstcase("test null format str")
	{
		cap_begin();
		num = ft_printf(NULL);
		cap_end(out, sizeof(out));
		tstcheck(num == 0 && strcmp(out, "") == 0, "ret=%d out=%s", num, out);
	}
	tstcase("test empty format str")
	{
		cap_begin();
		num = ft_printf("");
		cap_end(out, sizeof(out));
		expected_num = snprintf(expected, sizeof(expected), "%s", "");
		tstcheck(num == expected_num && strcmp(out, expected) == 0,
			"num=%d out=%s expected_num=%d expected=%s", num, out, expected_num,
			expected);
	}
	tstcase("test no conversions in format str")
	{
		cap_begin();
		num = ft_printf(format);
		cap_end(out, sizeof(out));
		expected_num = snprintf(expected, sizeof(expected), "%s", format);
		tstcheck(num == expected_num && strcmp(out, expected) == 0,
			"num=%d out=%s expected_num=%d expected=%s", num, out, expected_num,
			expected);
	}
}
