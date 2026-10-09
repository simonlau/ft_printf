/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:31:31 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/09 23:11:35 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "tst.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* PLACEHOLDER capture: redirect stdout to a tmpfile, read back into a
 * local array buffer. Passes against the current ft_printf stub
 * (returns 0, writes nothing). Replace the expected ret/out values
 * with real ones as conversions land. */
static FILE	*g_tmp = NULL;
static int	g_saved_stdout = -1;

static void	cap_begin(void)
{
	fflush(stdout);
	g_tmp = tmpfile();
	if (g_tmp == NULL)
		return ;
	g_saved_stdout = dup(STDOUT_FILENO);
	if (g_saved_stdout == -1)
	{
		fclose(g_tmp);
		g_tmp = NULL;
		return ;
	}
	dup2(fileno(g_tmp), STDOUT_FILENO);
}

static int	cap_end(char *out, size_t cap)
{
	size_t	n;

	fflush(stdout);
	if (g_saved_stdout == -1 || g_tmp == NULL)
		return (-1);
	dup2(g_saved_stdout, STDOUT_FILENO);
	close(g_saved_stdout);
	g_saved_stdout = -1;
	rewind(g_tmp);
	n = fread(out, 1, cap - 1, g_tmp);
	out[n] = '\0';
	fclose(g_tmp);
	g_tmp = NULL;
	return ((int)n);
}

tstsuite("ft_printf mandatory")
{
	tstcase("placeholder: plain string links and runs")
	{
		char	out[4096];
		int		ret;

		cap_begin();
		ret = ft_printf("hello");
		cap_end(out, sizeof(out));
		/* STUB expectation: writes nothing, returns 0. */
		tstcheck(ret == 0 && strcmp(out, "") == 0,
			"ret=%d out=\"%s\", stub expects ret=0 out=\"\"", ret, out);
	}

	tstcase("placeholder: conversions link and run")
	{
		char	out[4096];
		int		ret;

		cap_begin();
		ret = ft_printf("char %c str %s dec %d pct %%", 'Q', "hi", -7);
		cap_end(out, sizeof(out));
		/* STUB expectation: writes nothing, returns 0. */
		tstcheck(ret == 0 && strcmp(out, "") == 0,
			"ret=%d out=\"%s\", stub expects ret=0 out=\"\"", ret, out);
	}
}
