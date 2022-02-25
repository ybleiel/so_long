/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:19:04 by ybleiel           #+#    #+#             */
/*   Updated: 2022/02/24 12:06:00 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_floor(t_window *window, int x, int y)
{
	void	*img;
	char	*path;
	int		height;
	int		width;

	height = 50;
	width = 50;
	path = "assets/floor.xpm";
	img = mlx_xpm_file_to_image(window->mlx, path, &height, &width);
	mlx_put_image_to_window(window->mlx, window->mlx_win, img, x, y);
}

void	ft_set_player(t_window *window, int x, int y)
{
	void	*img;
	char	*path;
	int		height;
	int		width;

	height = 50;
	width = 50;
	path = "assets/player.xpm";
	img = mlx_xpm_file_to_image(window->mlx, path, &height, &width);
	mlx_put_image_to_window(window->mlx, window->mlx_win, img, x, y);
}

void	ft_set_wall(t_window *window, int x, int y)
{
	void	*img;
	char	*path;
	int		height;
	int		width;

	height = 50;
	width = 50;
	path = "assets/wall.xpm";
	img = mlx_xpm_file_to_image(window->mlx, path, &height, &width);
	mlx_put_image_to_window(window->mlx, window->mlx_win, img, x, y);
}

void	ft_set_collectible(t_window *window, int x, int y)
{
	void	*img;
	char	*path;
	int		height;
	int		width;

	height = 50;
	width = 50;
	path = "assets/collectible.xpm";
	img = mlx_xpm_file_to_image(window->mlx, path, &height, &width);
	mlx_put_image_to_window(window->mlx, window->mlx_win, img, x, y);
}

void	ft_set_exit(t_window *window, int x, int y)
{
	void	*img;
	char	*path;
	int		height;
	int		width;

	height = 50;
	width = 50;
	path = "assets/exit.xpm";
	img = mlx_xpm_file_to_image(window->mlx, path, &height, &width);
	mlx_put_image_to_window(window->mlx, window->mlx_win, img, x, y);
}
