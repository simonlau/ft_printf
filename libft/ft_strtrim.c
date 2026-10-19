/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/04 23:07:24 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	find_trim_bounds(const char *s1, const char *set,
				const char **start, const char **end)
{
	*start = s1;
	*end = s1 + ft_strlen(s1) - NULL_CHAR_ALLOC;
	while (**start != NULL_CHAR && ft_strchr(set, **start) != NULL)
		(*start)++;
	while (*end > *start && ft_strchr(set, **end) != NULL)
		(*end)--;
}

/**
 * @brief Allocates and returns a copy of s1 with characters
 * from set removed from beginning and end.
 * @param s1 The string to be trimmed.
 * @param set The string containing the set of characters to remove.
 * @return The trimmed string. NULL if allocation fails.
 *
 * @see raw/project-overview/libft-subject.md
 */
char	*ft_strtrim(const char *s1, const char *set)
{
	const char	*start;
	const char	*end;
	char		*result;
	int			len;

	if (s1 == NULL)
		return (ft_strdup(""));
	if (set == NULL)
		return (ft_strdup(s1));
	if (ft_strlen(s1) == 0 || ft_strlen(set) == 0)
		return (ft_strdup(s1));
	find_trim_bounds(s1, set, &start, &end);
	len = NULL_CHAR_ALLOC + NULL_CHAR_ALLOC + end - start;
	result = malloc(len * sizeof(*result));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, start, len);
	return (result);
}
