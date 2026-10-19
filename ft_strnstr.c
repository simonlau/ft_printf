/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/04 16:37:59 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of needle in haystack,
 * searching at most len characters.
 * @param haystack The string to search in.
 * @param needle The substring to search for.
 * @param len Maximum number of characters to search.
 * @return Pointer to the first occurrence of needle, or NULL if not found.
 *
 * @see man strnstr(3)
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	pos;
	char	curr;

	if (*needle == NULL_CHAR)
		return ((char *)haystack);
	i = 0;
	pos = 0;
	while (haystack[i] != NULL_CHAR && i < len)
	{
		pos = 0;
		curr = haystack[i + pos];
		while (curr != NULL_CHAR && i + pos < len && curr == needle[pos])
		{
			pos++;
			curr = haystack[i + pos];
		}
		if (needle[pos] == NULL_CHAR)
		{
			return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
