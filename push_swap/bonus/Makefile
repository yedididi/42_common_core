# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 12:06:19 by yejlee2           #+#    #+#              #
#    Updated: 2023/06/27 14:20:53 by yejlee2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = checker
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/utils_bonus.c \
		srcs/main_bonus.c \
		srcs/execute_bonus.c \
		srcs/parse_bonus.c \
		srcs/cmnd_pt_one_bonus.c \
		srcs/cmnd_pt_two_bonus.c \
		srcs/list_bonus.c \
		../get_next_line/get_next_line_utils.c \
		../get_next_line/get_next_line.c 
OBJS = $(SRCS:.c=.o)
INCS = include
LIBFT = ../libft/libft.a

.c.o :
	$(CC) -c $(CFLAGS) -o $@ $^ -I $(INCS)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT) : 
	make -C $(dir $(LIBFT))

clean :
	make -C $(dir $(LIBFT)) clean
	$(RM) $(OBJS)

fclean : clean
	make -C $(dir $(LIBFT)) fclean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re .c.o
