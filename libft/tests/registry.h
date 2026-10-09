/* ************************************************************************** */
/*                                                                            */
/*   Self-registering test registry                                           */
/*                                                                            */
/*   Each test file registers itself into g_tests via the REGISTER_TEST       */
/*   macro (a constructor), so the consolidated runner can never silently     */
/*   miss a test. The registry symbols live in exactly one TU (registry.c);   */
/*   every test TU only references them, so both the per-file and the         */
/*   consolidated builds link cleanly.                                        */
/*                                                                            */
/* ************************************************************************** */

#ifndef REGISTRY_H
# define REGISTRY_H

# include <stdlib.h>

struct s_test {
	const char	*name;
	int			(*run)(void);
	int			implemented;
};

# define MAX_TESTS 256

extern struct s_test	g_tests[MAX_TESTS];
extern int				g_test_count;

# define REGISTER_TEST(impl, fn) \
	static void fn##_reg(void) __attribute__((constructor, used)); \
	static void fn##_reg(void) \
	{ \
		if (g_test_count < MAX_TESTS) \
		{ \
			g_tests[g_test_count].name = #fn; \
			g_tests[g_test_count].run = fn; \
			g_tests[g_test_count].implemented = (impl); \
			g_test_count++; \
		} \
	}

#endif
