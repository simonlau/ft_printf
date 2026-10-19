/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/07 19:42:13 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares at most n bytes of strings s1 and s2.
 * @param s1 First string to compare.
 * @param s2 Second string to compare.
 * @param n Maximum number of bytes to compare.
 * @return Zero if equal, a non-zero difference otherwise.
 *
 * @see man strncmp(3)
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	char1;
	unsigned char	char2;
	int				diff;

	i = 0;
	while (i < n)
	{
		char1 = (unsigned char)s1[i];
		char2 = (unsigned char)s2[i];
		diff = char1 - char2;
		if (diff != 0 || char1 == NULL_CHAR)
		{
			return (diff);
		}
		i++;
	}
	return (EQUAL);
}
