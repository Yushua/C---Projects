/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_launch.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 04:47:25 by ybakker       #+#    #+#                 */
/*   Updated: 2022/05/12 15:33:53 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	first I create a thread for each one, then I make one extra for the check
	the run goes through the process of eating, sleeping and thinking

	the xtra thread (wait_death) checks, every so often, if something had
	died, else someone might die during a process. it also checks if people
	have eaten enough and gets the whole process out. because I use the
	integer dieded, if thats 1 it means that nothing will be writen and the
	funciton will stop the thread whe it stops after the process
*/

int	ft_launch(t_main *main)
{
	int				i;
	t_philosopher	*philo;

	i = 0;
	philo = main->philosophers;
	main->first_timestamp = ft_time();
	while (i < main->number_of_philosophers)
	{
		if (pthread_create(&(philo[i].thread), NULL, ft_run_philo, &(philo[i])))
			return (1);
		pthread_mutex_lock(&(main->t_t_d));
		philo[i].t_last_meal = ft_time();
		pthread_mutex_unlock(&(main->t_t_d));
		i++;
	}
	if (pthread_create(&(philo[i].thread), NULL, ft_wait_death, &(philo[i])))
		return (1);
	if (main->total_eat == 0 && main->nb_eat > 0 && main->dieded != 1)
		return (0);
	ft_exit(main, philo);
	return (0);
}
