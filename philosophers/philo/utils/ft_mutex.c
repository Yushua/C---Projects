/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mutex.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 02:01:23 by ybakker       #+#    #+#                 */
/*   Updated: 2022/04/11 15:25:09 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/

locking the threads

https://www.youtube.com/watch?v=nlHIuG3RQ0g

https://www.youtube.com/watch?v=oq29KUy29iQ

*/

int	ft_mutex(t_main *main)
{
	int	i;

	i = main->number_of_philosophers;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(main->forks[i]), NULL))
			return (-1);
	}
	if (pthread_mutex_init(&(main->writing_dead), NULL))
		return (-1);
	if (pthread_mutex_init(&(main->meal_check), NULL))
		return (-1);
	if (pthread_mutex_init(&(main->t_t_d), NULL))
		return (-1);
	return (0);
}
