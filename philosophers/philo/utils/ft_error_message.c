/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error_message.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 01:27:15 by ybakker       #+#    #+#                 */
/*   Updated: 2022/02/21 17:58:29 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_error_message(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (1);
}

int	ft_error_message_int(char *str, int i)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (i);
}
