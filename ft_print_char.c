/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:31:31 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/10 14:36:01 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	ft_putchar_fd(c, STDOUT_FILENO);
	return (1);
}

int	ft_print_str(char *s)
{
	/* TODO: print "(null)" for NULL, otherwise write the string. */
	(void)s;
	return (0);
}

int	ft_print_percent(void)
{
	/* TODO: write a single '%' and return 1. */
	return (0);
}
