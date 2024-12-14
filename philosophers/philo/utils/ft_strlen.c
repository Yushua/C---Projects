/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 01:28:05 by ybakker       #+#    #+#                 */
/*   Updated: 2021/11/29 15:17:14 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
