NAME	:= ft_containers
CXX		:= clang++ # change to clang++
CXXFLAGS:= -g -Wall -Wextra -Werror -std=c++98 #-fsanitize=address #delete -g -fsanitize=address

SRCS	:= main_map.cpp #main_total.cpp  #main_vector.cpp # main_map.cpp #   main_stack.cpp 
						
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