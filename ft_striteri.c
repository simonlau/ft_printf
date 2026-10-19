/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/07 18:32:48 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies the function f to each character of s,
 * passing its index as first argument.
 * @param s The string to iterate over.
 * @param f The function to apply to each character.
 * Each character is passed by address.
 *
 * @see raw/project-overview/libft-subject.md
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
	{
		return ;
	}
	i = 0;
	while (*s != NULL_CHAR)
	{
		f(i, s);
		s++;
		i++;
	}
}
