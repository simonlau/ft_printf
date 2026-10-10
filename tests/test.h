#ifndef FT_PRINT_TEST_H
# define FT_PRINT_TEST_H

# include "tst.h"
# include <stdio.h>
# include <unistd.h>

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

#endif
