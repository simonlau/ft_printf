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
#include <limits.h>

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

static long long	parse_digits(const char *str_ptr)
{
	long long	result;
	int			actual_digit;

	result = 0;
	while (*str_ptr != NULL_CHAR)
	{
		if (ft_isdigit(*str_ptr) == FALSE)
			break ;
		actual_digit = *str_ptr - '0';
		result = result * 10 + actual_digit;
		str_ptr++;
	}
	return (result);
}

/**
 * @brief Converts the initial portion of the string to an int.
 * @param str The string to convert to an integer.
 * @return The converted integer value.
 *
 * @see man atoi(3)
 */
int	ft_atoi(const char *str)
{
	long long		result;
	const char		*str_ptr;
	int				sign;

	result = 0;
	sign = 1;
	str_ptr = move_pass_spaces(str);
	if (*str_ptr == '+' || *str_ptr == '-')
	{
		if (*str_ptr == '-')
			sign = -sign;
		str_ptr++;
	}
	result = parse_digits(str_ptr);
	result = result * sign;
	if (result > INT_MAX)
		return (INT_MAX);
	if (result < INT_MIN)
		return (INT_MIN);
	return ((int)result);
}
