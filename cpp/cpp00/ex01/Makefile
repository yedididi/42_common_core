# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 14:38:56 by yejlee2           #+#    #+#              #
#    Updated: 2023/09/28 12:17:09 by yejlee2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
NAME = phonebook
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = phonebook.cpp main.cpp contact.cpp
INCS = phonebook.hpp main.hpp contact.hpp
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