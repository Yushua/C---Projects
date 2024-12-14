# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ybakker <ybakker@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/27 16:00:22 by ybakker       #+#    #+#                  #
#    Updated: 2021/09/24 13:58:50 by ybakker       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ex00

SRC = megaphone.cpp\

OBJ	= $(SRC:.cpp=.o)
CCFLAG = clang++
CPPFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98

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

test: $(NAME)
	./ex00 "shhhhh... I think the students are asleep..."
	./ex00 Damnit " ! " "Sorry students, I thought this thing was off."
	./ex00
