#include "libft.h"
#include "test.h"
#include "tst.h"
#include <stdlib.h>
#include <string.h>

tstsuite("ft_strrchr")
{
	char	*s;
	int		c;
	char	*expected;
	char	*result;
	int		i;

	srand(SEED);
	tstcase("property test matches strrchr oracle")
	{
		for (i = 0; i < TRIALS; i++)
		{
			s = make_rand_str();
			c = rand() % 256;
			tstexpect((expected = strrchr(s, c)) == (result = ft_strrchr(s, c)),
				"ft_strrchr(%s, %d)", s, c);
			free(s);
		}
	}
	tstcase("check special cases")
	{
		const char *tstdata[] = {"", "x", "abc", "hello world", "abc\0def"};
		tstsection("Check bounds")
		{
			c = rand() % 256;
			tstexpect((expected = strrchr(tstcurdata, c)) == (result = ft_strrchr(tstcurdata, c)),
				"ft_strrchr(%s, %d)", tstcurdata, c);
		}
	}
}
