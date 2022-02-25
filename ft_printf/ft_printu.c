/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:57:05 by ybleiel           #+#    #+#             */
/*   Updated: 2021/12/15 11:42:45 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include <stdlib.h>

int	ft_nbrlen(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*nbr;
	int		len;

	len = ft_nbrlen(n);
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (0);
	nbr[len] = '\0';
	while (n != 0)
	{
		nbr[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (nbr);
}

int	ft_printu(unsigned int u)
{
	char	*ustr;
	int		len;

	ustr = ft_uitoa(u);
	len = ft_strlen(ustr);
	if (u == 0)
	{
		write(1, "0", 1);
		free(ustr);
		return (1);
	}
	else
	{
		ft_putstr(ustr);
		free(ustr);
		return (len);
	}
}
