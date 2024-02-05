# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 11:29:07 by yejlee2           #+#    #+#              #
#    Updated: 2023/03/28 13:40:52 by yejlee2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = so_long
CFLAGS = -Wall -Wextra -Werror
SRC_FILE = main \
			check_map \
			print_map \
			init \
			play_game \
			reset_map \
			escapable \
			collect_all \
			so_long_utils
B_SRC_FILE = main \
			check_map \
			print_map \
			init \
			play_game \
			reset_map \
			escapable \
			collect_all \
			so_long_utils \
			put_enemy
SRC = $(addprefix mandatory/, $(addsuffix .c, $(SRC_FILE)))
OBJ = $(addprefix mandatory/, $(addsuffix .o, $(SRC_FILE)))
B_SRC = $(addprefix bonus/, $(addsuffix _bonus.c, $(B_SRC_FILE)))
B_OBJ = $(addprefix bonus/, $(addsuffix _bonus.o, $(B_SRC_FILE)))
MLX = minilibx_opengl_20191021
LIBFT = libft
INCLUDES = incs

ifdef WITH_BONUS
	OBJ_FILES = $(B_OBJ)
else
	OBJ_FILES = $(OBJ)
endif

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	make -C $(LIBFT)
	make -C $(MLX)
	$(CC) $(FLAGS) -I $(MLX) -L $(LIBFT) -lft -L $(MLX) -lmlx -framework OpenGL -framework AppKit $^ -o $@

bonus : $(B_OBJ)
	make WITH_BONUS=1 all

clean :
	rm -f $(OBJ)
	rm -f $(B_OBJ)
	make fclean -C $(LIBFT)
	make clean -C $(MLX)
	rm -f $(MLX)/libmlx

fclean : clean
	rm -f $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean bonus re
