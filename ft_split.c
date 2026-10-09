/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/08 12:53:17 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_words(const char *str, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = FALSE;
	while (*str != NULL_CHAR)
	{
		if (*str != c && in_word == FALSE)
		{
			in_word = TRUE;
			count++;
		}
		else if (*str == c)
			in_word = FALSE;
		str++;
	}
	return (count);
}

static void	free_all(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	*dup_range(const char *str, size_t start, size_t len)
{
	char	*word;
	size_t	i;

	word = malloc((len + NULL_CHAR_ALLOC) * sizeof(*word));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = NULL_CHAR;
	return (word);
}

static int	fill_split(char **arr, const char *str, char c)
{
	size_t	i;
	size_t	word;
	size_t	start;

	i = 0;
	word = 0;
	while (str[i] != NULL_CHAR)
	{
		while (str[i] != NULL_CHAR && str[i] == c)
			i++;
		if (str[i] == NULL_CHAR)
			break ;
		start = i;
		while (str[i] != NULL_CHAR && str[i] != c)
			i++;
		arr[word] = dup_range(str, start, i - start);
		if (arr[word] == NULL)
		{
			free_all(arr, word);
			return (FALSE);
		}
		word++;
	}
	arr[word] = NULL;
	return (TRUE);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	num_words;

	if (s == NULL)
		return (NULL);
	num_words = count_words(s, c);
	result = malloc((num_words + 1) * sizeof(*result));
	if (result == NULL)
		return (NULL);
	if (fill_split(result, s, c) == FALSE)
		return (NULL);
	return (result);
}
