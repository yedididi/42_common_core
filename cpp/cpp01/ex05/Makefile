# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 13:19:50 by yejlee2           #+#    #+#              #
#    Updated: 2023/09/29 14:54:02 by yejlee2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
NAME = Harl
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Harl.cpp
INCS = Harl.hpp
OBJS = $(SRCS:.cpp=.o)

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