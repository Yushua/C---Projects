# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ybakker <ybakker@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/27 16:00:22 by ybakker       #+#    #+#                  #
#    Updated: 2022/09/14 18:34:18 by ybakker       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COMPILE = c++
FLAGS = -Wall -Wextra -Werror -I. -std=c++98

NAME = Data

SRC = main.cpp\
		Data.cpp

INC = Data.hpp

OBJ = $(SRC:%.cpp=%.o)

%.o: %.cpp $(INC)
		$(COMPILE) $(FLAGS) -c $< -o $(<:.cpp=.o)

$(NAME): $(OBJ) $(INC)
	$(COMPILE) $(FLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)
fclean: clean
	@$(RM) $(NAME)
	@rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re test

st: re
	./$(NAME)
	make fclean