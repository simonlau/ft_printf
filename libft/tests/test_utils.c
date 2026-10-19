#include "libft.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include "test.h"

static void	del_noop(void *content)
{
	(void)content;
}

char	*make_rand_str(void)
{
	char	*s;
	int		len;

	s = malloc(1);
	if (s == NULL)
		return (NULL);
	len = rand() % 64;
	s = realloc(s, len + 1);
	if (s == NULL)
		return (NULL);
	for (int j = 0; j < len; j++)
		s[j] = (char)(rand() % 255 + 1);
	s[len] = '\0';
	return (s);
}

t_list	*make_rand_lst(int size)
{
	int		*arr;
	t_list	*head;
	t_list	*node;
	int		i;

	arr = make_rand_int_arr(size);
	if (arr == NULL)
		return (NULL);
	head = NULL;
	i = 0;
	while (i < size)
	{
		node = ft_lstnew((void *)(intptr_t)arr[i]);
		if (node == NULL)
		{
			ft_lstclear(&head, del_noop);
			free(arr);
			return (NULL);
		}
		ft_lstadd_back(&head, node);
		i++;
	}
	free(arr);
	return (head);
}

int	*make_rand_int_arr(int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * (size_t)size);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = rand();
		i++;
	}
	return (arr);
}

/* Read up to `count` bytes from `fd` into `buf`.
 * Returns the number of bytes read, or -1 on read error. */
ssize_t	capture_begin(int fd, void *buf, size_t count)
{
	size_t	total;
	ssize_t	r;

	total = 0;
	while (total < count)
	{
		r = read(fd, buf + total, count - total);
		if (r == 0)
			break ;
		if (r < 0)
			return (-1);
		total += (size_t)r;
	}
	return ((ssize_t)total);
}

/* Drain any remaining bytes from `fd`, then close it.
 * Returns the number of extra bytes read. */
size_t	capture_end(int fd)
{
	char	discard[4096];
	ssize_t	r;
	size_t	extra;

	extra = 0;
	while (1)
	{
		r = read(fd, discard, sizeof(discard));
		if (r == 0)
			break ;
		if (r < 0)
			break ;
		extra += (size_t)r;
	}
	close(fd);
	return (extra);
}

/* Run `body` once per trial, seeding `srand(seed)` internally.
 * Each invocation receives its zero-based trial index and the caller's ctx.
 * The caller owns any allocations made inside body. Returns void; failures
 * are reported by body through tstexpect. */
void	run_trials(int seed, int trials, void (*body)(int, void *), void *ctx)
{
	int	i;

	srand(seed);
	i = 0;
	while (i < trials)
	{
		body(i, ctx);
		i++;
	}
}

/* Assert that `fn(payload, fd)` writes exactly `expected` to `fd`.
 * Owns the pipe -> write -> close -> capture -> drain -> compare sequence
 * behind one seam. Uses a fixed internal buffer (heap if expected is large).
 * Returns 1 on match, 0 on mismatch; caller asserts via tstexpect. */
int		assert_fd_output(void (*fn)(void *, int fd), void *payload,
			 const char *expected, size_t expected_len)
{
	int		fds[2];
	char	stack[4096];
	char	*out;
	ssize_t	total;
	size_t	more;
	int		ok;

	out = stack;
	if (expected_len > sizeof(stack))
		out = malloc(expected_len);
	if (out == NULL)
		return (0);
	ok = 0;
	total = -1;
	more = 0;
	if (pipe(fds) == 0)
	{
		fn(payload, fds[PIPE_WRITE_END]);
		close(fds[PIPE_WRITE_END]);
		total = capture_begin(fds[PIPE_READ_END], out, expected_len);
		if (total >= 0)
		{
			more = capture_end(fds[PIPE_READ_END]);
			ok = ((size_t)total == expected_len && more == 0
			     && (expected_len == 0 || memcmp(out, expected, expected_len) == 0));
		}
	}
	if (out != stack)
		free(out);
	return (ok);
}
