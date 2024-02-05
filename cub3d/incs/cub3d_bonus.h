/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misukim <misukim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:12:01 by yejlee2           #+#    #+#             */
/*   Updated: 2023/12/01 14:41:24 by misukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx_opengl_20191021/mlx.h"

# define WIDTH 1280
# define HEIGHT 800

enum e_values
{
	WIN_WIDTH = 1280,
	WIN_HEIGHT = 800,
	MINIMAP_SIZE = 10,
	X_EVENT_KEY_PRESS = 2,
	X_EVENT_KEY_EXIT = 17,
	KEY_ESC	= 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	PLAYER_SPEED = 1
};

struct	s_mlx;

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		size_w;
	int		size_h;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_info
{
	double			player_row;
	double			player_col;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	void			*mlx;
	void			*win;
	double			move_speed;
	double			rot_speed;
	int				re_buf;
	int				**buf;
	int				**texture;
	struct s_img	*img;
}	t_info;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_dda
{
	double	camera_x;
	double	raydirx;
	double	raydiry;
	int		map_x;
	int		map_y;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		texnum;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	int		color;
	double	step;
	double	tex_pos;
	int		y;
}	t_dda;

typedef struct s_cub3d
{
	struct s_mlx	*mlx;
	struct s_info	*info;
	struct s_img	*texture_file;
	char			*file_name;
	char			**map;
	int				blank;
	int				row_size;
	int				col_size;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	int				f_color[3];
	int				c_color[3];
	int				contents;
	int				player;
	int				player_row;
	int				player_col;
	char			player_dir;
	int				floor;
	int				ceiling;
}	t_cub3d;

int		check_contents(char *line, t_cub3d *cub3d);
int		check_same_color(t_cub3d *cub3d);

void	wall_check(t_cub3d *cub3d);
void	check_wasd(t_cub3d *cub3d, int i, int j);
void	check_first_and_last(t_cub3d *cub3d);

void	free_and_exit(char *str, t_cub3d *cub3d);
void	free_only(t_cub3d *cub3d);

/* init */
void	init(t_cub3d *cub3d, char *file_name);
char	*check_file_name(char *file_name, t_cub3d *cub3d);
void	check_all_info_filled(t_cub3d *cub3d);
void	init_info(t_cub3d *cub3d);
void	init_texture(t_cub3d *cub3d);
void	init_dir(t_cub3d *cub3d);
void	init_other(t_cub3d *cub3d, char *file_name);

int		parse_file(t_cub3d *cub3d);
void	get_size(t_cub3d *cub3d);

char	*parse_info(t_cub3d *cub3d, int fd);
void	parse_map(t_cub3d *cub3d, int fd, char *line);

/* utils */
size_t	ft_isspace(const char *str);
int		found_map(char *line);
void	free_split(char **split);
int		ft_all_white(const char *str);
int		is_enter(char *str);
void	blank_flag(t_cub3d *cub3d);
void	check_another_map(t_cub3d *cub3d);
void	set_player_info(t_cub3d *cub3d, char player_dir, int col_size);

/* mlx */
void	print_minimap(t_cub3d *cub3d);
void	make_white_block(t_cub3d *cub3d, int x, int y);

/* key_press */
int		key_press(int key, t_cub3d *cub3d);
int		key_press_cross(t_cub3d *cub3d);
void	press_w(char **worldMap, t_info *info);
void	press_a(char **worldMap, t_info *info);
void	press_s(char **worldMap, t_info *info);
void	press_d(char **worldMap, t_info *info);

/* mouse */
void	key_left(int keycode, t_cub3d *cub3d);
void	key_right(int keycode, t_cub3d *cub3d);
void	draw_player(t_cub3d *cub3d);

/* dda */
void	basic_calculation(t_cub3d *cub3d, t_dda *dda, int x);
void	start_game(t_cub3d *cub3d);
void	help_get_texture(t_cub3d *cub3d, t_dda *dda);
void	fill_buffer(t_cub3d *cub3d, t_dda *dda, int x);

/* texture */
int		get_texnum(t_cub3d *cub3d, t_dda *dda);
int		*open_texture(t_cub3d *cub3d, int i, char *path);

#endif