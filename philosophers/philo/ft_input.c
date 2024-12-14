/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_input.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 15:05:55 by ybakker       #+#    #+#                 */
/*   Updated: 2022/05/12 15:34:23 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	inputting and making my functions work. i can now have acess to all my
	threads for my launch
*/

static void	st_save_input(t_main *main, char **argv)
{
	main->number_of_philosophers = ft_atoi(argv[1]);
	main->time_to_die = ft_atoi(argv[2]);
	main->time_to_eat = ft_atoi(argv[3]);
	main->time_to_sleep = ft_atoi(argv[4]);
	main->all_ate = 0;
	main->dieded = 0;
	main->nb_eat = -1;
	main->number_eat = -1;
}

static	int	st_check_input(t_main *main, char **argv)
{
	int		i;

	i = 0;
	if (main->number_of_philosophers < 1)
		i = ft_error_message_int("Number of Philosophers is lower than 1", 1);
	if (main->time_to_die < 0)
		i = ft_error_message_int("time to die input is lower than 0", 1);
	if (main->time_to_eat < 0)
		i = ft_error_message_int("Time to eat input is lower than 0", 1);
	if (main->time_to_sleep < 0)
		i = ft_error_message_int("Time to sleep input is lower than 0", 1);
	if (main->number_of_philosophers > 200)
		i = \
		ft_error_message_int("Number of Philosophers is higher than 200", 1);
	if (i != 0)
		return (i);
	if (argv[5])
	{
		main->nb_eat = ft_atoi(argv[5]);
		main->total_eat = main->nb_eat;
		main->number_eat = main->total_eat * main->number_of_philosophers;
		if (main->nb_eat <= 0)
			return (ft_error_message_int("numbers to eat is lower than 1", 1));
	}
	return (0);
}

int	ft_philo_fill(t_main *main)
{
	int	i;
	int	x;

	i = main->number_of_philosophers;
	x = main->number_of_philosophers;
	while (i >= 0)
	{
		main->philosophers[i].x = i;
		main->philosophers[i].x_ate = 0;
		main->philosophers[i].left_fork = i;
		main->philosophers[i].right_fork = (i + 1) % x;
		main->philosophers[i].t_last_meal = 0;
		main->philosophers[i].main = main;
		i--;
	}
	return (0);
}

static	int	st_is_number(char **argv)
{
	int	i;

	i = 0;
	if (argv[5])
	{
		if (ft_atoi(argv[5]) == 0)
			return (-1);
	}
	if ((ft_atoi(argv[1]) || ft_atoi(argv[2]) || ft_atoi(argv[3]) || \
	ft_atoi(argv[4])) == 0)
		return (-1);
	return (0);
}

int	ft_input(t_main *main, char **argv)
{
	int		i;

	i = 0;
	if (st_is_number(argv))
	{
		ft_error_message_int("input is not a number", 1);
		return (-1);
	}
	st_save_input(main, argv);
	i = st_check_input(main, argv);
	if (i != 0)
		return (i);
	else if (ft_mutex(main) == -1)
		return (2);
	ft_philo_fill(main);
	return (i);
}
