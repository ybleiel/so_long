/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:41:27 by ybleiel           #+#    #+#             */
/*   Updated: 2022/02/25 16:14:21 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../ft_printf/ft_printf.h"

# define BUFFER_SIZE 42

typedef struct s_position
{
	int			x;
	int			y;
	int			moves;
}				t_position;

typedef struct s_window
{
	void		*mlx;
	void		*mlx_win;
	int			win_size_x;
	int			win_size_y;
	char		*filepath;
	int			mapheight;
	int			mapwidth;
	int			nr;
	int			collectible;
	char		**map;
	t_position	*player;
}				t_window;

void	ft_set_player(t_window *window, int x, int y);
void	ft_set_floor(t_window *window, int x, int y);
void	ft_set_wall(t_window *window, int x, int y);
void	build_floor(t_window *window);
void	ft_init_map(t_window *window);
void	start_game(t_window *window);
void	ft_init_window(t_window *window);
int		ft_move_player(int keycode, t_window *window);
void	move_up(t_window *window);
int		ft_exit_game_cross(t_window *window);
void	ft_exit_game_esc(t_window *window);
char	*get_next_line(int fd);
void	build_map(t_window *window, int fd);
int		malloc_map(t_window *window);
void	ft_set_collectible(t_window *window, int x, int y);
void	ft_set_exit(t_window *window, int x, int y);
char	*ft_strchr(char *str, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
void	check_collectible(t_window *window);
void	check_exit(t_window *window);
void	ft_set_open_exit(t_window *window, int x, int y);
void	ft_set_enemy(t_window *window, int x, int y);
int		map_width(t_window *window);
int		map_height(t_window *window);
void	check_recktangle(int nr1, int nr2, char *nl);
void	check_assets(t_window *window, int x, int y, char *line);
void	check_cage(t_window *window, int fd);
void	map_invalid(t_window *window, char *line, int i, int y);
void	check_enemy(t_window *window);
void	move_count(t_window *window, int number);
void	check_chars(int x, char *line);

#endif