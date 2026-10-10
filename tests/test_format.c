/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:31:31 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/10 11:56:59 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h"

tstsuite("ft_printf format str only")
{
	char	out[4096];
	int		ret;
	char	format[] = "hello";

	tstcase("test null format str")
	{
		cap_begin();
		ret = ft_printf(NULL);
		cap_end(out, sizeof(out));
		tstcheck(ret == 0 && strcmp(out, "") == 0, "ret=%d out=%s", ret, out);
	}
	tstcase("test empty format str")
	{
		cap_begin();
		ret = ft_printf("");
		cap_end(out, sizeof(out));
		tstcheck(ret == 0 && strcmp(out, "") == 0, "ret=%d out=%s", ret, out);
	}
	tstcase("test no conversions in format str")
	{
		cap_begin();
		ret = ft_printf(format);
		cap_end(out, sizeof(out));
		tstcheck(ret == (int)strlen(format) && strcmp(out, format) == 0,
			"ret=%d out=%s", ret, out);
	}
}
