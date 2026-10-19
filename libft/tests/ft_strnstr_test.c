#include "libft.h"
#include "tst.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

#define HAY_MAX 15

static char	*expected_strnstr(const char *h, const char *n, size_t len)
{
	char	*w;

	w = strstr(h, n);
	if (w != NULL && (size_t)(w - h) + strlen(n) <= len)
		return (w);
	return (NULL);
}

static char	*gen_hay(int alphabet_bits)
{
	size_t	len;
	char	*s;
	size_t	i;

	len = (size_t)(rand() & 0xF);
	if (len > HAY_MAX)
		len = HAY_MAX;
	s = malloc(len + 1);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (alphabet_bits == 1)
			s[i] = (rand() & 1) ? 'b' : 'a';
		else
			s[i] = (char)(rand() & 0xFF);
		i++;
	}
	s[len] = '\0';
	return (s);
}

static int	check_lens(const char *h, const char *n)
{
	size_t	len;
	size_t	max;

	max = strlen(h) + 2;
	len = 0;
	while (len <= max)
	{
		if (ft_strnstr(h, n, len) != expected_strnstr(h, n, len))
			return (0);
		len++;
	}
	return (ft_strnstr(h, n, SIZE_MAX) == expected_strnstr(h, n, SIZE_MAX));
}

static int	check_junk(const char *h, const char *n)
{
	char	junk[20];
	size_t	hl;

	hl = strlen(h);
	if (hl > HAY_MAX)
		return (1);
	memcpy(junk, h, hl + 1);
	memset(junk + hl + 1, '#', sizeof(junk) - hl - 1);
	return (check_lens(junk, n));
}

static int	prop_sweep(const char *h, size_t p, size_t m)
{
	char	needle[HAY_MAX + 1];

	p = p % (strlen(h) + 1);
	m = m % (strlen(h) - p + 1);
	memcpy(needle, h + p, m);
	needle[m] = NULL_CHAR;
	if (!check_lens(h, needle) || !check_junk(h, needle))
		return (0);
	return (1);
}

static int	prop_diff(const char *h, const char *n, size_t len)
{
	return (ft_strnstr(h, n, len) == strnstr(h, n, len));
}

static int	prop_spec(const char *h, const char *n, size_t len)
{
	return (expected_strnstr(h, n, len) == strnstr(h, n, len));
}

tstsuite("ft_strnstr") {
    tstcase("prop spec: oracle matches system strnstr") {
        char	*h;
        char	*n;
        size_t	len;
        int		i;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            h = make_rand_str();
            n = make_rand_str();
            if (h == NULL || n == NULL)
            {
                free(h);
                free(n);
                continue ;
            }
            len = (size_t)rand();
            tstexpect(prop_spec(h, n, len),
                "expected_strnstr(%s, %s, %zu) != strnstr(%s, %s, %zu)",
                h, n, len, h, n, len);
            free(h);
            free(n);
        }
    }
    tstcase("prop sweep: alphabet {a,b}") {
        char	*h;
        size_t	p;
        size_t	m;
        int		i;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            h = gen_hay(1);
            if (h == NULL)
                continue ;
            p = (size_t)rand();
            m = (size_t)rand();
            tstexpect(prop_sweep(h, p, m),
                "strnstr sweep {a,b} mismatch for haystack len %zu", strlen(h));
            free(h);
        }
    }
    tstcase("prop sweep: full-byte alphabet") {
        char	*h;
        size_t	p;
        size_t	m;
        int		i;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            h = gen_hay(8);
            if (h == NULL)
                continue ;
            p = (size_t)rand();
            m = (size_t)rand();
            tstexpect(prop_sweep(h, p, m),
                "strnstr sweep byte mismatch for haystack len %zu", strlen(h));
            free(h);
        }
    }
    tstcase("prop diff: ft_strnstr matches system strnstr") {
        char	*h;
        char	*n;
        size_t	len;
        int		i;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            h = make_rand_str();
            n = make_rand_str();
            if (h == NULL || n == NULL)
            {
                free(h);
                free(n);
                continue ;
            }
            len = (size_t)rand();
            tstexpect(prop_diff(h, n, len),
                "ft_strnstr(%s, %s, %zu) != strnstr(%s, %s, %zu)",
                h, n, len, h, n, len);
            free(h);
            free(n);
        }
    }
}
