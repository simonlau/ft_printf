/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/04 16:36:10 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		target;
	const char	*current;
	const char	*result;

	target = (char)c;
	current = (const char *)s;
	result = NULL;
	while (*current)
	{
		if (*current == target)
		{
			result = current;
		}
		current++;
	}
	if (target == NULL_CHAR)
	{
		return ((char *)current);
	}
	return ((char *)result);
}
