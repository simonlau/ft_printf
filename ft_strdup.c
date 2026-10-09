/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/08 12:09:42 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*result;
	size_t	i;

	len = ft_strlen(s1) + NULL_CHAR_ALLOC;
	result = malloc(len * sizeof(*result));
	if (result == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		result[i] = s1[i];
		i++;
	}
	return (result);
}
