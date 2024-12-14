/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_launch_single.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 04:47:25 by ybakker       #+#    #+#                 */
/*   Updated: 2022/05/12 15:31:07 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	single is simple
	get the timestamp
	wait the wait
	it dies
	and return
*/

int	ft_launch_single(t_main *main)
{
	t_philosopher	*philo;

	philo = main->philosophers;
	main->first_timestamp = ft_time();
	printf("%lli %i %s\n", ft_time() - main->first_timestamp, 1, \
	"has taken a fork");
	usleep(main->time_to_die * 1000);
	printf("%lli %i %s\n", ft_time() - main->first_timestamp, 1, "died");
	return (0);
}
