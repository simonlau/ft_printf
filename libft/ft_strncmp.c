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
