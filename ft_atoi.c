/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/08 12:14:39 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_char_in_str(char c, const char *str)
{
	while (*str != NULL_CHAR)
	{
		if (*str == c)
		{
			return (TRUE);
		}
		str++;
	}
	return (FALSE);
}

static const char	*move_pass_spaces(const char *str)
{
	const char	*letter;

	letter = str;
	while (is_char_in_str(*letter, "\f\n\r \t\v"))
	{
		letter++;
	}
	return (letter);
}

int	ft_atoi(const char *str)
{
	long		result;
	const char	*str_ptr;
	int			sign;
	int			actual_digit;

	result = 0;
	sign = 1;
	str_ptr = move_pass_spaces(str);
	if (*str_ptr == '+' || *str_ptr == '-')
	{
		if (*str_ptr == '-')
			sign = -sign;
		str_ptr++;
	}
	while (*str_ptr != NULL_CHAR)
	{
		if (ft_isdigit(*str_ptr) == FALSE)
			return ((int)(result * sign));
		actual_digit = *str_ptr - '0';
		result = result * 10 + actual_digit;
		str_ptr++;
	}
	return ((int)(result * sign));
}
