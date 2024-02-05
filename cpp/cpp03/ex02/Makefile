# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejilee <yejilee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 16:34:18 by yejlee2           #+#    #+#              #
#    Updated: 2023/11/13 14:26:06 by yejilee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
NAME = ex00
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = ClapTrap.cpp FragTrap.cpp main.cpp
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

.PHONY : all clean fclean re .c.o%