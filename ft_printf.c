/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:31:31 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/10 10:45:55 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

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
		write(STDOUT_FILENO, format, sizeof(char));
		num_chars++;
		format++;
	}
	va_end(args);
	return (num_chars);
}
