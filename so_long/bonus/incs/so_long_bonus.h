/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:08:35 by yejlee2           #+#    #+#             */
/*   Updated: 2023/03/28 11:36:15 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"
# include "../../libft/libft.h"

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_param
{
	int		x_player;
	int		y_player;
}	t_param;

typedef struct s_map
{
	char	**map;
	int		e_count;
	int		c_count;
	int		p_count;
	int		x_map;
	int		y_map;
	int		flag;
}	t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		num;
	char	**map_v;
	char	**map_c;
	int		c_count_;
	t_map	sinnoh;
	t_param	param;
}	t_game;

void	error(char *message);

void	init(t_game *mix);
void	init_sinnoh(t_map *sinnoh);
void	init_mix(t_game *mix);
void	init_param(t_param *param);

void	check_map(char *map_name, t_map *sinnoh, t_param *param);
void	first_check(char *str, t_map *sinnoh);
void	middle_check(char *str, t_map *sinnoh, t_param *param);
void	last_check(char *str);
int		get_size(char *map_name);

void	print_map(t_game mix);
void	put_image(t_game mix, char *filename, int x, int y);
void	decide_tile(t_game mix, char c, int x, int y);

void	play_game(t_game *mix);
int		key_press(int keycode, t_game *mix);
int		so_close(void);

void	reset_map(t_map *sinnoh, t_param *param, int x_past, int y_past);
void	prevent_crush(t_param *param, int x_past, int y_past);
void	locate_player(t_map *sinnoh, t_param *param, int x_past, int y_past);
void	finish_game(t_map *sinnoh, t_param *param, int x_past, int y_past);

int		escapable(t_game *mix);
int		search_exit(t_game *mix, int x, int y, int num);
int		check_wasd(t_game *mix, int x, int y, char c);

int		check_wasd_c(t_game *mix, int x, int y, char c);
int		count_c(t_game *mix, int x, int y, int num);

void	free_double(char **str);
char	**duplicate(char **map, int size);
void	open_map(char *map_name, t_map *sinnoh);

void	put_enemy(t_game *mix);
void	move_enemy(t_map *sinnoh);
void	decide_enemy(t_map *sinnoh, int i, int j);
void	move_left(t_map *sinnoh, int i, int j);
void	move_right(t_map *sinnoh, int i, int j);

#endif