/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/09/24 00:36:21 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of c in the string s.
 * @param s The string to search.
 * @param c The character to locate.
 * @return Pointer to the matching character, or NULL if not found.
 *
 * @see man strchr(3)
 */
char	*ft_strchr(const char *s, int c)
{
	char	*pos;
	char	target;

	target = (char)c;
	pos = (char *)s;
	while (*pos)
	{
		if (*pos == target)
		{
			return (pos);
		}
		pos++;
	}
	if (*pos == target)
	{
		return (pos);
	}
	return (NULL);
}
