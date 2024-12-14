# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ybakker <ybakker@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/27 16:00:22 by ybakker       #+#    #+#                  #
#    Updated: 2022/09/16 15:39:40 by ybakker       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COMPILE = c++
FLAGS = -Wall -Wextra -Werror -I. -std=c++98

NAME = Convert

SRC = main.cpp\
		Convert.cpp

INC = Convert.hpp

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
	./$(NAME) -4.2
	./$(NAME) 0.256f
	./$(NAME) 18f
	./$(NAME) 4.24.2
	./$(NAME) 0.256f12
	./$(NAME) 68.12f
	./$(NAME) 1.34f
	./$(NAME) 1
	make fclean