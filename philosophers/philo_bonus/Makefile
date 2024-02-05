# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 13:58:05 by yejlee2           #+#    #+#              #
#    Updated: 2023/08/05 11:56:02 by yejlee2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = philo_bonus
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/action_bonus.c \
		srcs/check_bonus.c \
		srcs/execute_bonus.c \
		srcs/fill_bonus.c \
		srcs/main_bonus.c \
		srcs/utils_bonus.c \
		srcs/monitor_bonus.c
OBJS = $(SRCS:.c=.o)
INCS = ./incs

.c.o :
	$(CC) -c $(CFLAGS) -o $@ $^ -I $(INCS)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re .c.o