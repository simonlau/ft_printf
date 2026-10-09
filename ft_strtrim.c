/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/04 23:07:24 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	const char	*end_ptr;
	char		*result;
	int			len;

	if (ft_strlen(s1) == 0 || ft_strlen(set) == 0)
		return (ft_strdup(s1));
	end_ptr = s1 + ft_strlen(s1) - NULL_CHAR_ALLOC;
	while (*s1 != NULL_CHAR)
	{
		if (ft_strchr(set, *s1) == NULL)
			break ;
		s1++;
	}
	while (end_ptr > s1)
	{
		if (ft_strchr(set, *end_ptr) == NULL)
			break ;
		end_ptr--;
	}
	len = NULL_CHAR_ALLOC + NULL_CHAR_ALLOC + end_ptr - s1;
	result = malloc(len * sizeof(*result));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, len);
	return (result);
}
