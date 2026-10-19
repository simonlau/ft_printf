/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/08 12:43:58 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

/**
 * @brief Converts a letter to lowercase if it is uppercase.
 * @param c The character to convert.
 * @return The lowercase equivalent of c, or c unchanged if not uppercase.
 *
 * @see man tolower(3)
 */
int	ft_tolower(int c)
{
	int	diff;

	diff = 'a' - 'A';
	if (ft_isupper(c))
	{
		return (c + diff);
	}
	return (c);
}
