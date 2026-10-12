/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:31:31 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/12 22:02:17 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	int	count;
	int	negative_sign;
	int	final_digit;

	negative_sign = 1;
	final_digit = 1;
	ft_putnbr_fd(n, STDOUT_FILENO);
	if (n < 0)
	{
		count = negative_sign + final_digit;
	}
	else
	{
		count = final_digit;
	}
	while (n > 9 || n < -9)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static int	write_digits(unsigned int n, int fd)
{
	char	digit;
	int		count;

	if (n < 10)
	{
		digit = n + '0';
		ft_putchar_fd(digit, fd);
		return (1);
	}
	count = write_digits(n / 10, fd);
	return (count + write_digits(n % 10, fd));
}

int	ft_print_unsigned(unsigned int n)
{
	int	count;

	count = write_digits(n, STDOUT_FILENO);
	return (count);
}
