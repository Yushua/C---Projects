# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ybakker <ybakker@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/27 16:00:22 by ybakker       #+#    #+#                  #
#    Updated: 2021/09/24 14:11:13 by ybakker       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRC = tests.cpp\
	Account.cpp\

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

start:
	./$(NAME)
