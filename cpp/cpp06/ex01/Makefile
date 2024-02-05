# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 13:29:19 by yejlee2           #+#    #+#              #
#    Updated: 2024/01/04 16:17:55 by yejlee2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
NAME = ex01
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Serializer.cpp main.cpp
INCS = .
OBJS = $(SRCS:.cpp=.o)

.c.o :
	$(CC) -c $(CXXFLAGS) -o $@ $^ -I $(INCS)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re .c.o