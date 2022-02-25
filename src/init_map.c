/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:22:52 by ybleiel           #+#    #+#             */
/*   Updated: 2022/02/24 14:35:59 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_height(t_window *window)
{
	int		fd;
	int		nr_lines;
	char	*nl;

	fd = open(window->filepath, O_RDONLY);
	nr_lines = 0;
	nl = get_next_line(fd);
	while (nl != NULL)
	{
		free(nl);
		nr_lines++;
		nl = get_next_line(fd);
	}
	close(fd);
	free(nl);
	return (nr_lines);
}

int	map_width(t_window *window)
{
	int		nr_collums;
	char	*nl;
	char	size;
	int		fd;
	int		i;

	window->mapheight = map_height(window);
	fd = open(window->filepath, O_RDONLY);
	nl = get_next_line(fd);
	size = ft_strlen(nl);
	i = 1;
	while (nl != NULL)
	{
		nr_collums = ft_strlen(nl);
		if (i == window->mapheight)
			nr_collums++;
		check_recktangle(size, nr_collums, nl);
		free(nl);
		nl = get_next_line(fd);
		i++;
	}
	close(fd);
	free(nl);
	return (nr_collums - 1);
}

void	build_floor(t_window *window)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < window->win_size_x && y < window->win_size_y)
	{
		ft_set_floor(window, x, y);
		x += 50;
		if (x == window->win_size_x)
		{
			x = 0;
			y += 50;
		}
	}
}

void	build_map(t_window *window, int fd)
{
	char	*line;
	int		x;
	int		y;

	x = -1;
	y = 0;
	window->mapwidth = map_width(window);
	window->mapheight = map_height(window);
	line = malloc(window->mapwidth + 1);
	window->map = malloc((window->mapheight) * (window->mapwidth) + 1);
	line = get_next_line(fd);
	while (line[++x] != '\0')
	{
		window->map[y] = malloc((window->mapwidth) + 1);
		check_assets(window, x, y, line);
		if (line[x] == '\n')
		{
			x = -1;
			y++;
			free(line);
			line = get_next_line(fd);
		}
	}
	free(line);
	close(fd);
}

void	ft_init_map(t_window *window)
{
	int	fd;

	fd = open(window->filepath, O_RDONLY);
	check_cage(window, fd);
	build_floor(window);
	build_map(window, fd);
}
