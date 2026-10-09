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
