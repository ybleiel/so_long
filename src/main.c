/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:08:14 by ybleiel           #+#    #+#             */
/*   Updated: 2022/02/25 19:24:08 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_window(t_window *window)
{
	int	x;
	int	y;

	window->win_size_x = map_width(window) * 100;
	window->win_size_y = map_height(window) * 100;
	x = window->win_size_x;
	y = window->win_size_y;
	window->mlx = mlx_init();
	window->mlx_win = mlx_new_window(window->mlx, x - 10, y - 10, "so_long");
}

void	ft_check_filename(char **argv)
{
	int	len;
	int	e;

	e = 0;
	len = ft_strlen(argv[1]);
	if (argv[1][len - 1] != 'r')
		e = 1;
	if (argv[1][len - 2] != 'e')
		e = 1;
	if (argv[1][len - 3] != 'b')
		e = 1;
	if (argv[1][len - 4] != '.')
		e = 1;
	if (e == 1)
	{
		ft_printf("Filename not valid\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_window	*window;

	if (argc != 2)
		exit(0);
	window = (t_window *)malloc(1 * sizeof(t_window));
	window->player = (t_position *)malloc(1 * sizeof(t_position));
	window->filepath = argv[1];
	ft_check_filename(argv);
	ft_init_window(window);
	ft_init_map(window);
	mlx_string_put(window->mlx, window->mlx_win, 100, 97,
		0xff00, "Moves: ");
	mlx_key_hook(window->mlx_win, ft_move_player, window);
	mlx_hook(window->mlx_win, 17, 0, ft_exit_game_cross, window);
	mlx_loop(window->mlx);
	free(window);
	free(window->player);
	free(window->map);
	return (0);
}
