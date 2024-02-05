# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 11:31:10 by yejlee2           #+#    #+#              #
#    Updated: 2023/12/01 14:22:12 by yejlee2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = incs/cub3d.h
BONUS_HEADER = incs/cub3d_bonus.h
SRCS = srcs/main.c srcs/check_contents.c srcs/wall_check.c \
srcs/exit.c srcs/init.c srcs/parse_one.c srcs/parse_two.c srcs/utils.c \
srcs/hooks.c srcs/textured.c srcs/dda.c srcs/mouse.c \
srcs/texture.c srcs/utils_two.c srcs/init_two.c
BONUS_SRCS = bonus_files/main_bonus.c bonus_files/check_contents_bonus.c bonus_files/wall_check_bonus.c \
bonus_files/exit_bonus.c bonus_files/init_bonus.c bonus_files/parse_one_bonus.c bonus_files/parse_two_bonus.c bonus_files/utils_bonus.c \
bonus_files/hooks_bonus.c bonus_files/minimap_bonus.c bonus_files/player_bonus.c bonus_files/textured_bonus.c bonus_files/dda_bonus.c bonus_files/mouse_bonus.c \
bonus_files/texture_bonus.c bonus_files/utils_two_bonus.c bonus_files/init_two_bonus.c
INCS = incs
MAN_OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
LIBFT_DIR = ./libft
LIBFT_A = -lft -L$(LIBFT_DIR)
MLX = $(MLX_DIR)libmlx.a
MLX_DIR = ./minilibx_opengl_20191021/
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
NAME = cub3D

ifdef IS_BONUS
	OBJS = $(BONUS_OBJS)
	INCS = $(BONUS_HEADER)
else
	OBJS = $(MAN_OBJS)
	INCS = $(HEADER)
endif

.c.o :
	$(CC) -c $(CFLAGS) -o $@ $< -I $(INCS)

all: $(NAME)

$(MLX):
	make -C $(MLX_DIR)

$(NAME): $(OBJS) $(MLX)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(LIBFT_A) $(OBJS)

bonus:
	sleep 0.1
	make IS_BONUS=1 all

clean:
	make -C $(LIBFT_DIR) clean
	make clean -C $(MLX_DIR)
	rm -f $(BONUS_OBJS)
	rm -f $(MAN_OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
