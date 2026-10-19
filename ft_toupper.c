/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/08 12:44:10 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

/**
 * @brief Converts a letter to uppercase if it is lowercase.
 * @param c The character to convert.
 * @return The uppercase equivalent of c, or c unchanged if not lowercase.
 *
 * @see man toupper(3)
 */
int	ft_toupper(int c)
{
	int	diff;

	diff = 'a' - 'A';
	if (ft_islower(c))
	{
		return (c - diff);
	}
	return (c);
}
