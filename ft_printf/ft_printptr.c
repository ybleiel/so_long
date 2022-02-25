/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:53:12 by ybleiel           #+#    #+#             */
/*   Updated: 2021/12/13 13:51:05 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_ptrlen(uintptr_t nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 16;
	}
	return (len);
}

void	ft_putptr(uintptr_t nbr)
{
	if (nbr >= 16)
	{
		ft_putptr(nbr / 16);
		ft_putptr(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd((nbr + '0'), 1);
		else
			ft_putchar_fd((nbr - 10 + 'a'), 1);
	}
}

int	ft_printptr(unsigned long long ptr)
{
	int	print_lgth;

	print_lgth = 0;
	print_lgth += write(1, "0x", 2);
	if (ptr == 0)
		print_lgth += write(1, "0", 1);
	else
	{
		ft_putptr(ptr);
		print_lgth += ft_ptrlen(ptr);
	}
	return (print_lgth);
}
