/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/08 12:54:33 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *str, size_t max)
{
	size_t	i;

	i = 0;
	while (str[i] != NULL_CHAR && i < max)
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	dst_len = ft_strnlen(dst, dstsize);
	i = 0;
	dst += dst_len;
	if (dst_len >= dstsize)
		return (dst_len + src_len);
	while (i < src_len)
	{
		if (dst_len + i >= dstsize - 1)
			break ;
		dst[i] = src[i];
		i++;
	}
	dst[i] = NULL_CHAR;
	return (dst_len + src_len);
}
