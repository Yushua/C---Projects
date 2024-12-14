/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_time.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 01:31:27 by ybakker       #+#    #+#                 */
/*   Updated: 2021/11/23 05:31:11 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	ft_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}
