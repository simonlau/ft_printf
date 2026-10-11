/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:31:31 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/11 19:17:02 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static int	print_hex(uintptr_t num)
{
	char		*digits;
	int			total;
	uintptr_t	hex_num;

	digits = "0123456789abcdef";
	hex_num = 16;
	if (num < hex_num)
	{
		ft_putchar_fd(digits[num], STDOUT_FILENO);
		return (1);
	}
	total = print_hex(num / hex_num);
	return (total + print_hex(num % hex_num));
}

int	ft_print_hex(unsigned int n, int uppercase)
{
	char			*digits;
	unsigned int	hex_num;
	int				total;

	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	hex_num = 16;
	if (n < hex_num)
	{
		ft_putchar_fd(digits[n], STDOUT_FILENO);
		return (1);
	}
	total = ft_print_hex(n / hex_num, uppercase);
	return (total + ft_print_hex(n % hex_num, uppercase));
}

int	ft_print_ptr(void *p)
{
	char		*null_msg;
	char		*prefix;
	char		*str;
	int			num;
	uintptr_t	address;

	null_msg = "(nil)";
	if (p == NULL)
	{
		str = null_msg;
		ft_putstr_fd(str, STDOUT_FILENO);
		return (ft_strlen(null_msg));
	}
	prefix = "0x";
	ft_putstr_fd(prefix, STDOUT_FILENO);
	address = (uintptr_t)p;
	num = print_hex(address) + ft_strlen(prefix);
	return (num);
}
