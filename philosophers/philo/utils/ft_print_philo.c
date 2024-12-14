/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_philo.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 19:58:49 by ybakker       #+#    #+#                 */
/*   Updated: 2022/04/19 16:25:27 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/* 
lockign the multiplex, writting the commands
cannot write if there is a dead
*/

void	ft_print_philo(t_main *main, int x, char *command)
{
	pthread_mutex_lock(&(main->writing_dead));
	if (main->dieded == 0)
	{
		printf("%lli %i %s\n", \
		ft_time() - main->first_timestamp, x, command);
	}
	pthread_mutex_unlock(&(main->writing_dead));
	return ;
}
