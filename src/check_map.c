/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:52:46 by ybleiel           #+#    #+#             */
/*   Updated: 2022/02/24 12:34:46 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_collectible(t_window *window)
{
	int	x;
	int	y;

	x = window->player->x;
	y = window->player->y;
	if (window->map[y][x] == 'C')
	{
		window->collectible += 1;
		window->map[y][x] = '0';
	}
}

void	check_exit(t_window *window)
{
	int	x;
	int	y;

	x = window->player->x;
	y = window->player->y;
	if (window->map[y][x] == 'E' && window->collectible == window->nr)
	{
		ft_set_open_exit(window, x * 100, y * 100);
		window->collectible = 10;
	}
	else if (window->map[y][x] == 'E' && window->collectible == 10)
	{
		ft_set_player(window, x * 100, y * 100);
		window->player->moves += 1;
		ft_printf("Moves: %d\n", window->player->moves);
		ft_printf("You Won!\n");
		exit(0);
	}
	check_enemy(window);
}

void	check_recktangle(int nr1, int nr2, char *nl)
{
	if (nr1 != nr2)
	{
		ft_printf("Error: Invalid map\n");
		free(nl);
		exit(0);
	}
}

void	check_assets(t_window *window, int x, int y, char *line)
{
	if (line[x] == '1')
		ft_set_wall(window, x * 100, y * 100);
	if (line[x] == 'P')
	{
		ft_set_player(window, x * 100, y * 100);
		window->player->x = x;
		window->player->y = y;
	}
	if (line[x] == 'C')
	{
		ft_set_collectible(window, x * 100, y * 100);
		window->nr += 1;
	}
	if (line[x] == 'E')
		ft_set_exit(window, x * 100, y * 100);
	if (line[x] == 'X')
		ft_set_enemy(window, x * 100, y * 100);
	if (line[x] == '\n' || line[x] == '\0')
			window->map[y] = ft_strdup(line);
}

void	check_cage(t_window *window, int fd)
{
	int		i;
	int		y;
	char	*line;

	fd = open(window->filepath, O_RDONLY);
	i = 0;
	y = 0;
	line = malloc(window->mapwidth + 1);
	line = get_next_line(fd);
	while (line[i] != '\0')
	{
		map_invalid(window, line, i, y);
		i++;
		if (line[i] == '\n')
		{
			i = 0;
			y++;
			free(line);
			line = get_next_line(fd);
		}
	}
	free(line);
}
