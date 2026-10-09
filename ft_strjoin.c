/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/04 23:06:38 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	len;
	char	*result;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	len = s1_len + s2_len;
	result = malloc(NULL_CHAR_ALLOC + len * sizeof(*result));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, s1_len + NULL_CHAR_ALLOC);
	ft_strlcat(result, s2, len + NULL_CHAR_ALLOC);
	return (result);
}
