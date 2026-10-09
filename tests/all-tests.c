/* ************************************************************************** */
/*                                                                            */
/*   all-tests.c                                                              */
/*                                                                            */
/*   Runs every registered test in its own child process so a crash or        */
/*   sanitizer abort in one test cannot take down the rest of the suite.      */
/*   Reports PASS / FAIL / CRASH / NOT IMPLEMENTED and exits non-zero if      */
/*   any implemented test fails.                                              */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "registry.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(void)
{
	size_t	total = (size_t)g_test_count;
	size_t	pass = 0;
	size_t	fail = 0;
	size_t	notimpl = 0;

	for (size_t i = 0; i < total; i++)
	{
		pid_t	pid = fork();
		if (pid < 0)
		{
			printf("ERROR: fork failed for %s\n", g_tests[i].name);
			fail++;
			continue;
		}
		if (pid == 0)
		{
			int	r = g_tests[i].run();
			_exit(r);
		}
		int	status;
		waitpid(pid, &status, 0);
		if (WIFSIGNALED(status))
		{
			printf("CRASH %s (signal %d)\n", g_tests[i].name, WTERMSIG(status));
			fail++;
		}
		else
		{
			int	code = WEXITSTATUS(status);
			if (!g_tests[i].implemented)
			{
				printf("NOT IMPLEMENTED %s\n", g_tests[i].name);
				notimpl++;
			}
			else if (code == 0)
			{
				printf("PASS %s\n", g_tests[i].name);
				pass++;
			}
			else
			{
				printf("FAIL %s (exit %d)\n", g_tests[i].name, code);
				fail++;
			}
		}
	}
	printf("\n%zu passed, %zu failed, %zu not implemented, %zu total\n",
		pass, fail, notimpl, total);
	return (fail ? EXIT_FAILURE : EXIT_SUCCESS);
}
