/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:22:55 by ybleiel           #+#    #+#             */
/*   Updated: 2021/12/14 11:26:09 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int nbr, const char format)
{
	if (nbr >= 16)
	{
		ft_puthex(nbr / 16, format);
		ft_puthex(nbr % 16, format);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd((nbr + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((nbr - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((nbr - 10 + 'A'), 1);
		}
	}
}

int	ft_hexlen(unsigned int nbr)
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

int	ft_printhex(unsigned int nbr, const char format)
{
	if (nbr == 0)
		return (write(1, "0", 1));
	else
		ft_puthex(nbr, format);
	return (ft_hexlen(nbr));
}
