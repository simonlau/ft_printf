/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/08 12:49:13 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dest_ptr;
	const char	*src_ptr;
	size_t		pos;

	dest_ptr = (char *)dst;
	src_ptr = (const char *)src;
	i = 0;
	while (i < len)
	{
		if (dst < src)
		{
			dest_ptr[i] = src_ptr[i];
		}
		else
		{
			pos = len - NULL_CHAR_ALLOC - i;
			dest_ptr[pos] = src_ptr[pos];
		}
		i++;
	}
	return (dst);
}
