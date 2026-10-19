/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/08 12:55:07 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief Applies the function f to each character of s,
 * passing its index as first argument.
 * @param s The string to iterate over.
 * @param f The function to apply to each character.
 * @return The string created from the successive applications of f.
 * NULL if allocation fails.
 *
 * @see raw/project-overview/libft-subject.md
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*result;
	unsigned int	i;

	len = ft_strlen(s);
	result = malloc((len + NULL_CHAR_ALLOC) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = NULL_CHAR;
	i = 0;
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	return (result);
}
