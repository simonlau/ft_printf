/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/08 12:46:44 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static long	ft_abs(int n)
{
	if (n < 0)
	{
		return (-(long)n);
	}
	return ((long)n);
}

static int	calc_negative_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static size_t	count_digits(long num, int negative_sign)
{
	int	current_digit_space;
	int	minus_sign_space;

	current_digit_space = 1;
	if (num < 10)
	{
		if (negative_sign)
		{
			minus_sign_space = 1;
			return (current_digit_space + minus_sign_space);
		}
		return (current_digit_space);
	}
	return (current_digit_space + count_digits(num / 10, negative_sign));
}

static char	digit_to_char(int digit)
{
	if (digit > 9 || digit < 0)
	{
		return (NULL_CHAR);
	}
	return (digit + '0');
}

char	*ft_itoa(int n)
{
	char	*result;
	int		negative_sign;
	size_t	len;
	size_t	i;
	long	num;

	num = ft_abs(n);
	negative_sign = calc_negative_sign(n);
	len = count_digits(num, negative_sign);
	result = malloc((len + NULL_CHAR_ALLOC) * sizeof(*result));
	if (!result)
		return (NULL);
	result[len] = NULL_CHAR;
	i = 0;
	while (i < len)
	{
		result[len - NULL_CHAR_ALLOC - i] = digit_to_char(num % 10);
		num /= 10;
		i++;
	}
	if (negative_sign == 1)
		result[0] = '-';
	return (result);
}
