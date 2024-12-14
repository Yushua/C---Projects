/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_diff.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 17:40:16 by ybakker       #+#    #+#                 */
/*   Updated: 2022/04/13 17:41:39 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_check_diff(t_philosopher *philo, t_main *main)
{
	pthread_mutex_lock(&(main->t_t_d));
	if ((ft_time() - philo->t_last_meal) > main->time_to_die)
	{
		pthread_mutex_unlock(&(main->t_t_d));
		return (1);
	}
	pthread_mutex_unlock(&(main->t_t_d));
	return (0);
}
