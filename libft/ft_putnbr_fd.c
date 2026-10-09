/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/06 18:14:30 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	write_digits(unsigned int n, int fd)
{
	char	digit;

	if (n < 10)
	{
		digit = n + '0';
		ft_putchar_fd(digit, fd);
		return ;
	}
	write_digits(n / 10, fd);
	write_digits(n % 10, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = -(long)n;
	}
	else
	{
		num = n;
	}
	write_digits(num, fd);
}
