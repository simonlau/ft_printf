/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/04 16:28:01 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Calculates the length of the string s, excluding
 * the terminating null byte.
 * @param s The string whose length to calculate.
 * @return The length of the string.
 *
 * @see man strlen(3)
 */
size_t	ft_strlen(const char *s)
{
	size_t	count;

	if (s == NULL)
	{
		return (0);
	}
	count = 0;
	while (*s != NULL_CHAR)
	{
		s++;
		count++;
	}
	return (count);
}
