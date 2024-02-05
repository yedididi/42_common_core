# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 15:12:14 by yejlee2           #+#    #+#              #
#    Updated: 2023/05/11 12:05:47 by yejlee2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = pipex
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/execute.c srcs/main.c srcs/parsing.c
OBJS = $(SRCS:.c=.o)
INCS = include
LIBFT = libft/libft.a

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
