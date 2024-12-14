/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 15:02:43 by ybakker       #+#    #+#                 */
/*   Updated: 2022/05/12 15:34:57 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	checing for errors, chekcing if the input is right
	if the input is 0 it will also be wrong, but this is due to the limit I
	have wiht my check.
*/

int	main(int argc, char **argv)
{
	t_main	main;

	if (argc < 5)
		return (ft_error_message("Number of arguments are either too low"));
	else if (argc > 6)
		return (ft_error_message("Number of arguments are either too high"));
	if (ft_input(&main, argv))
	{
		return (ft_error_message("input failed"));
	}
	if (main.number_of_philosophers >= 2)
	{
		if (ft_launch(&main))
			return (ft_error_message("launch failed"));
	}
	else if (ft_launch_single(&main))
		return (ft_error_message("launch failed"));
	return (0);
}
