CXX = c++
NAME = ex02
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp
INCS = .
OBJS = $(SRCS:.cpp=.o)

.c.o :
	$(CXX) -c $(CXXFLAGS) -o $@ $^ -I $(INCS)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re .c.o