/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:23:59 by ybleiel           #+#    #+#             */
/*   Updated: 2022/02/22 12:56:20 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_format(va_list args, const char format)
{
	int	print_lgth;

	print_lgth = 0;
	if (format == 'c')
		print_lgth += ft_printc(va_arg(args, int));
	if (format == 's')
		print_lgth += ft_prints(va_arg(args, char *));
	else if (format == 'p')
		print_lgth += ft_printptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_lgth += ft_printdori(va_arg(args, int));
	else if (format == 'u')
		print_lgth += ft_printu(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_lgth += ft_printhex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_lgth += ft_printperc();
	return (print_lgth);
}

int	ft_printf(const char *st, ...)
{
	int		i;
	int		print_lgth;
	va_list	args;

	i = 0;
	print_lgth = 0;
	va_start(args, st);
	while (st[i])
	{
		if (st[i] == '%')
		{
			print_lgth += ft_format(args, st[i + 1]);
			i++;
		}
		else
			print_lgth += ft_printc(st[i]);
		i++;
	}
	va_end(args);
	return (print_lgth);
}
