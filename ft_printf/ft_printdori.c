/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdori.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:39:23 by ybleiel           #+#    #+#             */
/*   Updated: 2021/12/13 12:04:46 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size(int n)
{
	int	result;

	if (n <= 0)
		result = 1;
	else
		result = 0;
	while (n != 0)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char			*result;
	unsigned int	number;
	int				size;

	if (n < 0)
		number = -n;
	else
		number = n;
	size = ft_size(n);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	result[size--] = '\0';
	while (size >= 0)
	{
		result[size] = number % 10 + 48;
		number = number / 10;
		size--;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}

int	ft_printdori(int di)
{
	char	*distr;
	int		len;

	distr = ft_itoa(di);
	len = ft_strlen(distr);
	ft_putstr(distr);
	free(distr);
	return (len);
}
