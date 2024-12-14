# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ybakker <ybakker@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/28 16:04:32 by ybakker       #+#    #+#                  #
#    Updated: 2022/08/17 12:36:43 by ybakker       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ZombieHorde

SRC = main.cpp\
	Zombie.cpp\
	ZombieHorde.cpp\

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
re: fclean all

st: re
	./$(NAME)
