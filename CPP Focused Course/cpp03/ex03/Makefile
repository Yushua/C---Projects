# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ybakker <ybakker@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/27 16:00:22 by ybakker       #+#    #+#                  #
#    Updated: 2022/08/27 21:09:49 by ybakker       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = Claptrap

SRC = main.cpp\
		ClapTrap.cpp\
		ScavTrap.cpp\
		FragTrap.cpp\
		DiamondTrap.cpp\
	
OBJ	= $(SRC:.cpp=.o)
CCFLAG = c++
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

st: re clean
	./$(NAME)
	make fclean