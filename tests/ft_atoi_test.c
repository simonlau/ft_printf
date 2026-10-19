#include "libft.h"
#include "test.h"
#include "tst.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tstsuite("ft_atoi")
{
	unsigned int	n;
	char			buf[256];
	const char		*sign;
	int				result;
	int				expected;
	int				i;
	int				val;

	tstcase("property test matches atoi oracle")
	{
		srand(SEED);
		for (i = 0; i < TRIALS; i++)
		{
			val = rand() % INT_MAX - (rand() % 2);
			n = (unsigned int)val;
			sign = n % 3 == 0 ? "+" : (n % 3 == 1 ? "-" : "");
			snprintf(buf, sizeof(buf), "%*s%s%d", n % 20, "", sign, val);
			tstexpect((result = ft_atoi(buf)) == (expected = atoi(buf)),
				"ft_atoi(%d) = %d != %d", val, result, expected);
		}
	}
	tstcase("edge overflow and INT_MIN boundaries")
	{
		const char *tstdata[] = {
			"2147483647",  /* INT_MAX (boundary, well-defined) */
			"-2147483648", /* INT_MIN (boundary, well-defined) */
			"+2147483647",
			"-2147483648",
			"  2147483647",
			"\t-2147483648",
			"",      /* empty -> 0 */
			"   ",   /* whitespace only -> 0 */
			"+-12",  /* invalid sign sequence -> 0 */
			"--12",  /* invalid sign sequence -> 0 */
			"12abc", /* stops at first non-digit -> 12 */
		};
		tstsection("edge overflow and INT_MIN boundaries")
		{
			tstexpect((result = ft_atoi(tstcurdata)) == (expected = atoi(tstcurdata)),
				"ft_atoi(\"%s\") = %d != %d", tstcurdata, result, expected);
		}
	}
	tstcase("edge overflow clamps to INT_MIN and INT_MAX")
	{
		const char *tstdata[] = {
			"2147483648",   /* INT_MAX + 1 -> clamp to INT_MAX */
			"-2147483649",  /* INT_MIN - 1 -> clamp to INT_MIN */
			"999999999999", /* way beyond -> INT_MAX */
			"-999999999999",/* way beyond -> INT_MIN */
			"+2147483648",  /* signed INT_MAX + 1 -> clamp to INT_MAX */
		};
		int expected[] = {
			INT_MAX,
			INT_MIN,
			INT_MAX,
			INT_MIN,
			INT_MAX,
		};
		int n = sizeof(tstdata) / sizeof(tstdata[0]);

		for (i = 0; i < n; i++)
		{
			result = ft_atoi(tstdata[i]);
			tstexpect(result == expected[i],
				"ft_atoi(\"%s\") = %d, expected %d", tstdata[i], result, expected[i]);
		}
	}
}
