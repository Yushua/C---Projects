# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ybakker <ybakker@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/27 16:00:22 by ybakker       #+#    #+#                  #
#    Updated: 2021/04/26 10:21:18 by ybakker       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COMPILE = clang++
FLAGS = -Wall -Wextra -Werror -I. -std=c++98
CPP = main.cpp\
	Fixed.cpp\

NAME = ex01

OBJ	= $(CPP:.cpp=.o)

.PHONY: all clean fclean re test
all: $(NAME)
$(NAME): $(OBJ)
	$(COMPILE) $(FLAGS) -o $(NAME) $(OBJ)
clean:
	rm -rf $(OBJ)
fclean: clean
	@$(RM) $(NAME)
	@rm -f $(NAME)
	@rm -f ./testfiles/test.txt.replace
re: fclean all

test: re
	./ex01
