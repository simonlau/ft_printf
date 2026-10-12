/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 11:00:00 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/12 22:00:52 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h"
#include <limits.h>
#include <stdlib.h>
#include <string.h>

tstsuite("ft_printf hex")
{
	char			out[OUT_MAX];
	char			expected[OUT_MAX];
	int				num;
	int				expected_num;
	unsigned int	tstdata[NUM_TRIALS];
	unsigned int	vals[] = {0x0U, 0x1U, 0x9U, 0xAU, 0xFU, 0x10U, 0xFFU,
			0x100U, 0xFFFU, 0x1000U, 0xFFFFU, 0x10000U, 0xABCDEFU, 0xDEADBEEFU,
			0x12345678U, 0x7FFFFFFFU, 0x7FFFFFFEU, 0x80000000U, 0x80000001U,
			0xFFFFFFFEU, 0xFFFFFFFFU};

	srand(SEED);
	tstcase("unsigned int")
	{
		for (int i = 0; i < NUM_TRIALS; i++)
		{
			tstdata[i] = (((unsigned int)rand() << 16) ^ (unsigned int)rand());
		}
		tstsection("check lower")
		{
			cap_begin();
			num = ft_printf("%x", tstcurdata);
			cap_end(out, sizeof(out));
			expected_num = snprintf(expected, sizeof(expected), "%x",
					tstcurdata);
			tstexpect(num == expected_num && strcmp(out, expected) == 0,
				"num=%d out=%s expected_num=%d expected=%s", num, out,
				expected_num, expected);
		}
		tstsection("check upper")
		{
			cap_begin();
			num = ft_printf("%X", tstcurdata);
			cap_end(out, sizeof(out));
			expected_num = snprintf(expected, sizeof(expected), "%X",
					tstcurdata);
			tstexpect(num == expected_num && strcmp(out, expected) == 0,
				"num=%d out=%s expected_num=%d expected=%s", num, out,
				expected_num, expected);
		}
	}
	tstcase("unsigned edges")
	{
		for (size_t i = 0; i < sizeof(vals) / sizeof(vals[0]); i++)
		{
			tstsection("check lower")
			{
				cap_begin();
				num = ft_printf("%x", vals[i]);
				cap_end(out, sizeof(out));
				expected_num = snprintf(expected, sizeof(expected), "%x",
						vals[i]);
				tstexpect(num == expected_num && strcmp(out, expected) == 0,
					"num=%d out=%s expected_num=%d expected=%s", num, out,
					expected_num, expected);
			}
			tstsection("check upper")
			{
				cap_begin();
				num = ft_printf("%X", vals[i]);
				cap_end(out, sizeof(out));
				expected_num = snprintf(expected, sizeof(expected), "%X",
						vals[i]);
				tstexpect(num == expected_num && strcmp(out, expected) == 0,
					"num=%d out=%s expected_num=%d expected=%s", num, out,
					expected_num, expected);
			}
		}
	}
}
