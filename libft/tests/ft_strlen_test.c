#include "libft.h"
#include "test.h"
#include "tst.h"
#include <stdlib.h>
#include <string.h>

tstsuite("ft_strlen")
{
	char	*s;
	size_t	result;
	size_t	expected;
	int		i;

	srand(SEED);
	tstcase("property test matches strlen oracle")
	{
		for (i = 0; i < TRIALS; i++)
		{
			s = make_rand_str();
			tstexpect((expected = strlen(s)) == (result = ft_strlen(s)),
				"ft_strlen(%s) = %zu != %zu", s, result, expected);
			free(s);
		}
	}
	tstcase("check special cases")
	{
		const char *tstdata[] = {"", "x", "abc\0def"};
		tstsection("Check bounds")
		{
			tstexpect((expected = strlen(tstcurdata)) == (result = ft_strlen(tstcurdata)),
				"ft_strlen(%s) = %zu != %zu", tstcurdata, result, expected);
		}
	}
}
