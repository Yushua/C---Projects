/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dead.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 17:42:04 by ybakker       #+#    #+#                 */
/*   Updated: 2022/05/06 17:01:47 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_dead(t_philosopher *philo, t_main *main)
{
	pthread_mutex_lock(&(main->writing_dead));
	if (ft_check_diff(philo, main) == 1 && main->dieded != 1)
	{
		main->dieded = 1;
		printf("%lli %i %s\n", \
		ft_time() - main->first_timestamp, philo->x + 1, "died");
		pthread_mutex_unlock(&(main->forks[philo->left_fork]));
		pthread_mutex_unlock(&(main->forks[philo->right_fork]));
	}
	pthread_mutex_unlock(&(main->writing_dead));
	return (1);
}
