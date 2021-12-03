NAME	:= ft_containers
CXX		:= c++ # change to clang++
CXXFLAGS:= -g -Wall -Wextra -Werror -std=c++98 -fsanitize=address #delete -g -fsanitize=address

SRCS	:= main.cpp \
			vector.cpp
						
OBJS	:= $(SRCS:.cpp=.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME)	: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all