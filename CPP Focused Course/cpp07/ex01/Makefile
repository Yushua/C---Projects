# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ybakker <ybakker@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/27 16:00:22 by ybakker       #+#    #+#                  #
#    Updated: 2022/08/28 03:45:39 by ybakker       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COMPILE = c++
FLAGS = -Wall -Wextra -Werror -I. -std=c++98

NAME = Data

SRC = main.cpp

OBJ	= $(SRC:.cpp=.o)
CCFLAG = c++
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

st: re
	./$(NAME)
	make fclean