/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_wait_death.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/06 17:57:55 by ybakker       #+#    #+#                 */
/*   Updated: 2022/05/12 15:37:59 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	I constantly check if something has died, BECAUSE I DON'T WANT TO OVERUSE
	MY MUTEXES, i make fucniton that get the vlaue form that mutex at that
	moment, this way I don't use it for a whole while loop. this means I open
	and close more, but i also make sure my other processes can work as well

	 check if someone has died, or if everyone has eaten enough
*/

static int	st_get_dead(t_main *main)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(main->writing_dead));
	i = main->dieded;
	pthread_mutex_unlock(&(main->writing_dead));
	return (i);
}

static int	st_wait_here(t_main *main, int x)
{
	if (x == main->number_of_philosophers)
	{
		x = 0;
		usleep(2000);
	}
	return (x);
}

static int	st_check_eat(t_main *main)
{
	pthread_mutex_lock(&(main->meal_check));
	if (main->number_eat == 0)
	{
		main->dieded = st_get_dead(main);
		pthread_mutex_unlock(&(main->meal_check));
		return (0);
	}
	pthread_mutex_unlock(&(main->meal_check));
	return (1);
}

static void	st_check_dead(t_main *main, int x)
{
	main->dieded = 1;
	printf("%lli %i %s\n", \
	ft_time() - main->first_timestamp, x + 1, "died");
}

void	*ft_wait_death(void *void_philosopher)
{
	t_philosopher	*philo;
	t_main			*main;
	int				x;

	philo = (t_philosopher *)void_philosopher;
	main = philo->main;
	x = 0;
	usleep(2000);
	while (st_get_dead(main) == 0)
	{
		x = st_wait_here(main, x);
		if (st_check_eat(main) == 0)
			return (0);
		pthread_mutex_lock(&(main->writing_dead));
		if (((ft_time() - main->philosophers[x].t_last_meal) > \
		main->time_to_die) && main->dieded != 1)
			st_check_dead(main, x);
		pthread_mutex_unlock(&(main->writing_dead));
		usleep(10);
		x++;
	}
	return (NULL);
}
