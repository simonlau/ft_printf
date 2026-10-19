/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/09/26 22:14:06 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Scans the first n bytes of memory area s for the first instance of c.
 * @param s Pointer to the memory area to search.
 * @param c The byte to search for.
 * @param n Number of bytes to be analyzed.
 * @return Pointer to the matching byte, or NULL if not found.
 *
 * @see man memchr(3)
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*pos;
	unsigned char	target;
	size_t			i;

	target = (unsigned char)c;
	pos = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*pos == target)
		{
			return (pos);
		}
		pos++;
		i++;
	}
	return (NULL);
}
