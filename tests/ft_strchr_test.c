#include "libft.h"
#include "test.h"
#include "tst.h"
#include <stdlib.h>
#include <string.h>

tstsuite("ft_strchr")
{
	char	*s;
	int		c;
	char	*expected;
	char	*result;
	int		i;

	srand(SEED);
	tstcase("property test matches strchr oracle")
	{
		for (i = 0; i < TRIALS; i++)
		{
			s = make_rand_str();
			c = rand() % 256;
			tstexpect((expected = strchr(s, c)) == (result = ft_strchr(s, c)),
				"ft_strchr(%s, %d)", s, c);
			free(s);
		}
	}
	tstcase("check special cases")
	{
		const char *tstdata[] = {"", "x", "abc", "hello world", "abc\0def"};
		tstsection("Check bounds")
		{
			c = rand() % 256;
			tstexpect((expected = strchr(tstcurdata, c)) == (result = ft_strchr(tstcurdata, c)),
				"ft_strchr(%s, %d)", tstcurdata, c);
		}
	}
}
