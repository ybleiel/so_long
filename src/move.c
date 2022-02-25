/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:27:27 by ybleiel           #+#    #+#             */
/*   Updated: 2022/02/24 13:47:40 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_window *window)
{
	int	x;
	int	y;

	window->player->y -= 1;
	x = window->player->x;
	y = window->player->y;
	check_collectible(window);
	check_exit(window);
	if (window->map[y][x] == '0')
	{
		ft_set_player(window, x * 100, y * 100);
		ft_set_floor(window, x * 100, y * 100 + 100);
		window->map[y + 1][x] = '0';
		window->player->moves += 1;
		ft_printf("Moves: %d\n", window->player->moves);
		move_count(window, window->player->moves);
	}	
	else
		window->player->y += 1;
}

void	move_left(t_window *window)
{
	int	x;
	int	y;

	window->player->x -= 1;
	x = window->player->x;
	y = window->player->y;
	check_collectible(window);
	check_exit(window);
	if (window->map[y][x] == '0')
	{
		ft_set_player(window, x * 100, y * 100);
		ft_set_floor(window, x * 100 + 100, y * 100);
		window->map[y][x + 1] = '0';
		window->player->moves += 1;
		ft_printf("Moves: %d\n", window->player->moves);
		move_count(window, window->player->moves);
	}
	else
		window->player->x += 1;
}

void	move_down(t_window *window)
{
	int	x;
	int	y;

	window->player->y += 1;
	x = window->player->x;
	y = window->player->y;
	check_collectible(window);
	check_exit(window);
	if (window->map[y][x] == '0')
	{
		ft_set_player(window, x * 100, y * 100);
		ft_set_floor(window, x * 100, y * 100 - 100);
		window->map[y - 1][x] = '0';
		window->player->moves += 1;
		ft_printf("Moves: %d\n", window->player->moves);
		move_count(window, window->player->moves);
	}
	else
		window->player->y -= 1;
}

void	move_right(t_window *window)
{
	int	x;
	int	y;

	window->player->x += 1;
	x = window->player->x;
	y = window->player->y;
	check_collectible(window);
	check_exit(window);
	if (window->map[y][x] == '0')
	{
		ft_set_player(window, x * 100, y * 100);
		ft_set_floor(window, x * 100 - 100, y * 100);
		window->map[y][x - 1] = '0';
		window->player->moves += 1;
		ft_printf("Moves: %d\n", window->player->moves);
		move_count(window, window->player->moves);
	}
	else
		window->player->x -= 1;
}

int	ft_move_player(int keycode, t_window *window)
{
	if (keycode == 13)
		move_up(window);
	else if (keycode == 0)
		move_left(window);
	else if (keycode == 1)
		move_down(window);
	else if (keycode == 2)
		move_right(window);
	else if (keycode == 53)
		ft_exit_game_esc(window);
	return (0);
}
