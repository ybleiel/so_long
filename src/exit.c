/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:55:32 by ybleiel           #+#    #+#             */
/*   Updated: 2022/02/24 12:07:32 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit_game_esc(t_window *window)
{
	free(window);
	exit(0);
}

int	ft_exit_game_cross(t_window *window)
{
	free(window);
	exit(0);
	return (0);
}

void	map_invalid(t_window *window, char *line, int i, int y)
{
	int	lenght;

	lenght = ft_strlen(line);
	if (line[i] != '1' && y == 0)
	{
		ft_printf("Map invalid\n");
		exit(0);
	}
	if (line[0] != '1' || line[lenght - 2] != '1')
	{
		ft_printf("Map invalid\n");
		exit(0);
	}
	if (line[i] != '1' && y == window->mapheight - 1)
	{
		ft_printf("Map invalid\n");
		exit(0);
	}
	y++;
}
