/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_single_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 11:00:00 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/10 13:33:58 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h"
#include <string.h>

tstsuite("ft_printf single char")
{
	char	out[OUT_MAX];
	int		ret;

	tstcase("placeholder: single char links and runs")
	{
		cap_begin();
		ret = ft_printf("%c", 'A');
		cap_end(out, sizeof(out));
		/* PLACEHOLDER: %c not dispatched yet, format is echoed
			* literally. Expect ret=2 out="%c"; replace with ret=1
			* out="A" once %c lands. */
		tstcheck(ret == 1 && strcmp(out, "A") == 0, "ret=%d out=%s", ret, out);
	}
	// tstcase("placeholder: single char edge links and runs")
	// {
	// 	cap_begin();
	// 	ret = ft_printf("%c%c", 'A', 'B');
	// 	cap_end(out, sizeof(out));
	// 	/* PLACEHOLDER: see above; replace with ret=2 out="AB". */
	// 	tstcheck(ret == 4 && strcmp(out, "%c%c") == 0, "ret=%d out=%s", ret,
	// 		out);
	// }
}
