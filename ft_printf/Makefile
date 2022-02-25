# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 11:38:25 by ybleiel           #+#    #+#              #
#    Updated: 2021/12/14 12:38:19 by ybleiel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- MakeFile -*-

SOURCE =	ft_printf.c ft_printdori.c ft_printc.c ft_printhex.c \
			ft_printperc.c ft_printptr.c ft_prints.c ft_printu.c \
			ft_putstr.c ft_strlen.c \
			
OBJECTS =	$(SOURCE:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

all:	$(NAME)

libftprintf.a:	$(OBJECTS)
	ar rs $(NAME) $(OBJECTS)

$(OBJECTS):	$(SOURCE)
	$(CC) -c $(CFLAGS) $(SOURCE)

clean:
	rm -f $(OBJECTS)

fclean: 	clean
	rm -f libftprintf.a

re:		fclean all