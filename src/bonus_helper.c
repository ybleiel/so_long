/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:12:27 by ybleiel           #+#    #+#             */
/*   Updated: 2022/02/24 14:35:34 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_open_exit(t_window *window, int x, int y)
{
	void	*img;
	char	*path;
	int		height;
	int		width;

	height = 50;
	width = 50;
	path = "assets/open_exit.xpm";
	img = mlx_xpm_file_to_image(window->mlx, path, &height, &width);
	mlx_put_image_to_window(window->mlx, window->mlx_win, img, x, y);
}

void	ft_set_enemy(t_window *window, int x, int y)
{
	void	*img;
	char	*path;
	int		height;
	int		width;

	height = 50;
	width = 50;
	path = "assets/enemy.xpm";
	img = mlx_xpm_file_to_image(window->mlx, path, &height, &width);
	mlx_put_image_to_window(window->mlx, window->mlx_win, img, x, y);
}

void	check_enemy(t_window *window)
{
	int	x;
	int	y;

	x = window->player->x;
	y = window->player->y;
	if (window->map[y][x] == 'X')
	{
		ft_printf("You lose :(\n");
		exit(0);
	}
}

void	ft_set_mini_floor(t_window *window, int x, int y)
{
	void	*img;
	char	*path;
	int		height;
	int		width;

	height = 50;
	width = 50;
	path = "assets/mini_floor.xpm";
	img = mlx_xpm_file_to_image(window->mlx, path, &height, &width);
	mlx_put_image_to_window(window->mlx, window->mlx_win, img, x, y);
}

void	move_count(t_window *window, int number)
{
	char	*str;

	str = ft_itoa(number);
	ft_set_mini_floor(window, 175, 87);
	mlx_string_put(window->mlx, window->mlx_win, 175, 97,
		0xff00, str);
}
