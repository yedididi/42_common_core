# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 11:50:11 by yejlee2           #+#    #+#              #
#    Updated: 2023/06/27 12:42:33 by yejlee2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRCS = mandatory/srcs/list.c \
		mandatory/srcs/main.c \
		mandatory/srcs/main_utils.c \
		mandatory/srcs/parse.c \
		mandatory/srcs/pivot.c \
		mandatory/srcs/op_one.c \
		mandatory/srcs/op_two.c \
		mandatory/srcs/op_three.c \
		mandatory/srcs/sort.c \
		mandatory/srcs/greedy.c \
		mandatory/srcs/calculate_one.c \
		mandatory/srcs/calculate_two.c \
		mandatory/srcs/free.c
OBJS = $(SRCS:.c=.o)
INCS = mandatory/incs
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
