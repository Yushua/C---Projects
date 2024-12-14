# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ybakker <ybakker@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/23 05:14:41 by ybakker       #+#    #+#                  #
#    Updated: 2022/05/06 17:58:39 by ybakker       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


NAME	= philo
COMPILER	= gcc
FLAGS	= -Wall -Werror -Wextra

SRCS	= 	main.c\
			./utils/ft_error_message.c\
			./utils/ft_strlen.c\
			./utils/ft_atoi.c\
			./utils/ft_mutex.c\
			./utils/ft_time.c\
			./utils/ft_run_philo.c\
			./utils/ft_eats.c\
			./utils/ft_check_diff.c\
			./utils/ft_dead.c\
			./utils/ft_print_philo.c\
			./utils/ft_sleep_check.c\
			./utils/ft_exit.c\
			ft_input.c\
			ft_launch_single.c\
			ft_launch.c\
			ft_wait_death.c\

HEADER	= philo.h
OBJS	= $(SRCS:.c=.o)


all:	$(NAME)

.PHONY:	clean fclean re

$(NAME): $(OBJS)
	$(COMPILER) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

%.o: %.c $(HEADER)
	$(COMPILER) $(FLAGS) -c $<  -o $(<:.c=.o)

test: re
	./$(NAME) 3 2000 200 200 5 > file1
