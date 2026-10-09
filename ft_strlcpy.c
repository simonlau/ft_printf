/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/04 16:33:17 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	if (size == 0)
	{
		return (len);
	}
	if (size == 1)
	{
		*dst = NULL_CHAR;
		return (len);
	}
	i = 0;
	while (i < size - 1 && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = NULL_CHAR;
	return (len);
}
