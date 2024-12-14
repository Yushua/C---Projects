/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_run.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/22 22:07:41 by ybakker       #+#    #+#                 */
/*   Updated: 2022/05/06 16:59:27 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
runs itself
time difference if the person is at sleep
*/

static void	st_waiting(t_main *main)
{
	if (main->time_to_eat < 2)
		usleep(2000);
	else
		usleep(main->time_to_eat * 1000 - 1000);
}

static int	st_get_dead(t_main *main)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(main->writing_dead));
	i = main->dieded;
	pthread_mutex_unlock(&(main->writing_dead));
	return (i);
}

void	*ft_run_philo(void *void_philosopher)
{
	t_philosopher	*philo;
	t_main			*main;

	philo = (t_philosopher *)void_philosopher;
	main = philo->main;
	if (philo->x % 2)
		st_waiting(main);
	while (st_get_dead(main) == 0)
	{
		ft_eats(philo);
		pthread_mutex_lock(&(main->writing_dead));
		if (main->number_eat == 0)
		{
			main->dieded = 1;
			pthread_mutex_unlock(&(main->writing_dead));
			return (NULL);
		}
		pthread_mutex_unlock(&(main->writing_dead));
		ft_print_philo(main, philo->x + 1, "is sleeping");
		ft_sleep_check(main->time_to_sleep, main);
		ft_print_philo(main, philo->x + 1, "is thinking");
	}
	return (NULL);
}
