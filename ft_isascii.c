/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/04 16:27:08 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks whether c is a 7-bit unsigned char value that
 * fits in the ASCII set.
 * @param c The character to check.
 * @return Non-zero if c is ASCII, 0 otherwise.
 *
 * @see man isascii(3)
 */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 0177)
	{
		return (TRUE);
	}
	return (FALSE);
}
