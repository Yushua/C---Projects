# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ybakker <ybakker@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/27 16:00:22 by ybakker       #+#    #+#                  #
#    Updated: 2021/04/26 10:16:02 by ybakker       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COMPILE = clang++
FLAGS = -Wall -Wextra -Werror -I. -std=c++98

NAME = ex01

SRC = Fixed.cpp\
		main.cpp\

OBJ	= $(SRC:.cpp=.o)
CCFLAG = clang++
CPPFLAGS = -Wall -Wextra -Werror -I. -std=c++98

.PHONY: all clean fclean re test
all: $(NAME)
$(NAME): $(OBJ)
	$(CCFLAG) $(CPPFLAGS) -o $(NAME) $(OBJ)
clean:
	rm -rf $(OBJ)
fclean: clean
	@$(RM) $(NAME)
	@rm -f $(NAME)
	@rm -f ./testfiles/test.txt.replace
re: fclean all

test: re
	./ex01
