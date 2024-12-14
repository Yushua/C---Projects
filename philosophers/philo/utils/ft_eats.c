/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_eats.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 15:11:24 by ybakker       #+#    #+#                 */
/*   Updated: 2022/05/06 17:56:12 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
chekcing if a fork is done, and waiting until the enxt fork.
is there a way something will be waiting for a fork?
no, because it goes arond, it is hwoever bad luck on the phio
*/

static void	st_check_for_eats(t_main *main, t_philosopher *philo)
{
	pthread_mutex_lock(&(main->meal_check));
	if (main->nb_eat < 0)
		ft_print_philo(main, philo->x + 1, "is eating");
	else if (main->number_eat > 0 && philo->x_ate <= main->nb_eat)
	{
		ft_print_philo(main, philo->x + 1, "is eating");
		main->number_eat--;
		philo->x_ate++;
	}
	pthread_mutex_unlock(&(main->meal_check));
	return ;
}

void	ft_eats(t_philosopher *philo)
{
	t_main	*main;

	main = philo->main;
	pthread_mutex_lock(&(main->forks[philo->left_fork]));
	ft_print_philo(main, philo->x + 1, "has taken a fork");
	pthread_mutex_lock(&(main->forks[philo->right_fork]));
	ft_print_philo(main, philo->x + 1, "has taken a fork");
	if (ft_dead(philo, main) == 0)
		return ;
	st_check_for_eats(main, philo);
	pthread_mutex_lock(&(main->t_t_d));
	philo->t_last_meal = ft_time();
	pthread_mutex_unlock(&(main->t_t_d));
	ft_sleep_check(main->time_to_eat, main);
	pthread_mutex_unlock(&(main->forks[philo->left_fork]));
	pthread_mutex_unlock(&(main->forks[philo->right_fork]));
}
