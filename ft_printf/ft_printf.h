/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:29:37 by ybleiel           #+#    #+#             */
/*   Updated: 2022/02/24 13:28:22 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>

int		ft_printf(const char *st, ...);
void	ft_putstr(char *st);
int		ft_printc(int c);
int		ft_printperc(void);
int		ft_prints(char *s);
int		ft_printdori(int di);
int		ft_printu(unsigned int u);
size_t	ft_strlen(const char *s);
int		ft_printptr(unsigned long long ptr);
int		ft_printhex(unsigned int nbr, const char format);
void	ft_putchar_fd(char c, int fd);
char	*ft_itoa(int n);

#endif