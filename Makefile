# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 12:02:26 by ybleiel           #+#    #+#              #
#    Updated: 2022/02/25 11:27:38 by ybleiel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =			src/main.c src/init_map.c src/exit.c src/get_next_line.c \
				src/get_next_line_utils.c src/move.c src/images.c \
				src/check_map.c src/bonus_helper.c

OBJS		=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Werror -Wextra

%.o: %.c 
		gcc $(CFLAGS) -Imlx -c $< -o $@

so_long:	$(OBJS)
			cd mlx && make
			cd ft_printf && make
			gcc $(OBJS) ft_printf/libftprintf.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

all:		so_long

clean:
		cd mlx && make clean
		cd ft_printf && make clean
		rm -rf $(OBJS)

fclean: clean
		rm -rf so_long
		rm -rf ft_printf/libftprintf.a
		rm -rf libmlx.a

re: fclean all