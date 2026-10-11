/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:31:31 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/11 12:09:09 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	ft_putchar_fd(c, STDOUT_FILENO);
	return (sizeof(char));
}

int	ft_print_str(char *s)
{
	char	*null_msg;
	char	*str;

	null_msg = "(null)";
	if (s == NULL)
	{
		str = null_msg;
	}
	else
	{
		str = s;
	}
	ft_putstr_fd(str, STDOUT_FILENO);
	return (ft_strlen(str));
}

int	ft_print_percent(void)
{
	ft_print_char('%');
	return (sizeof(char));
}
