/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:31:31 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/10 12:04:16 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

tstsuite("ft_printf bonus")
{
	char	out[OUT_MAX];

	tstcase("test null format str")
	{
		cap_begin();
		cap_end(out, sizeof(out));
	}
	/* TODO: add tstcase blocks. */
}
