/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sleep_check.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 02:23:55 by ybakker       #+#    #+#                 */
/*   Updated: 2022/04/11 15:10:08 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
	waits until its time to eat
	else it waits a bit
*/

void	ft_sleep_check(long long time, t_main *main)
{
	long long	i;
	int			dead;

	i = ft_time();
	pthread_mutex_lock(&(main->writing_dead));
	dead = main->dieded;
	pthread_mutex_unlock(&(main->writing_dead));
	while (!(dead))
	{
		pthread_mutex_lock(&(main->writing_dead));
		dead = main->dieded;
		pthread_mutex_unlock(&(main->writing_dead));
		if ((ft_time() - i) >= time)
			break ;
		usleep(100);
	}
}
