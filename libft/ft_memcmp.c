/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/04 16:37:22 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares the first n bytes of memory areas s1 and s2.
 * @param s1 Pointer to the first memory area.
 * @param s2 Pointer to the second memory area.
 * @param n Number of bytes to compare.
 * @return Zero if the areas are equal, a non-zero difference otherwise.
 *
 * @see man memcmp(3)
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*str1 = (const char *)s1;
	const char	*str2 = (const char *)s2;
	int			diff;

	i = 0;
	while (i < n)
	{
		diff = (unsigned char)str1[i] - (unsigned char)str2[i];
		if (diff != 0)
		{
			return (diff);
		}
		i++;
	}
	return (EQUAL);
}
