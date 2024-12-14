/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_exit.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 02:32:45 by ybakker       #+#    #+#                 */
/*   Updated: 2022/04/13 18:00:37 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_exit(t_main *main, t_philosopher *philos)
{
	int	i;

	i = -1;
	while (++i <= main->number_of_philosophers)
		pthread_join(philos[i].thread, NULL);
	i = -1;
	while (++i <= main->number_of_philosophers)
		pthread_mutex_destroy(&(main->forks[i]));
	pthread_mutex_destroy(&(main->meal_check));
	pthread_mutex_destroy(&(main->writing_dead));
	pthread_mutex_destroy(&(main->t_t_d));
}
