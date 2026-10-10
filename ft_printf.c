/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:31:31 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/10 15:06:07 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	convert(char c, va_list *args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(*args, int)));
	else if (c == 's')
		return (ft_print_str(va_arg(*args, char *)));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(*args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(*args, int)));
	else if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(*args, int), c == 'X'));
	else if (c == '%')
		return (ft_print_percent());
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	num_chars;
	int				result;

	num_chars = 0;
	if (format == NULL)
		return (0);
	va_start(args, format);
	while (*format != NULL_CHAR)
	{
		if (*format == '%')
		{
			format++;
			result = convert(*format, &args);
			if (result == -1)
				return (-1);
			num_chars += result;
		}
		else
			num_chars += ft_print_char(*format);
		format++;
	}
	va_end(args);
	return (num_chars);
}
