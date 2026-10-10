/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:31:31 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/10 13:15:11 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	handle_char(int c)
{
	ft_putchar_fd(c, STDOUT_FILENO);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	num_chars;

	num_chars = 0;
	if (format == NULL)
		return (0);
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				num_chars += handle_char(va_arg(args, int));
		}
		else
		{
			write(STDOUT_FILENO, format, sizeof(char));
			num_chars++;
		}
		format++;
	}
	va_end(args);
	return (num_chars);
}
