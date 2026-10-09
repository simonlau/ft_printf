/* ************************************************************************** */
/*                                                                            */
/*   Registry storage (single definition, linked by every test binary).       */
/*                                                                            */
/* ************************************************************************** */

#include "registry.h"

struct s_test	g_tests[MAX_TESTS];
int				g_test_count = 0;

/* lets huge-but-non-overflowing allocs return NULL instead of aborting under ASan */
const char	*__asan_default_options(void)
{
	return ("allocator_may_return_null=1");
}
