/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 18:29:25 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/28 19:42:04 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** find first argument, if first argument is not a number keep looking.
** if number argument is found, check for anything that isn't ' ' or
** ><;|\n or \0.
*/

/*
** exit code: 255 for if a numeric value is found but it contains alpha chars, 
** also use the first arg found as error message. but still exit.
** ie. exit hello 12cab
** program exits with exit code 255, hello is used as arg.
** for exit 123 abc
** the program will NOT exit, it will print a warning: too many arguments.
** for exit hello 123
** the program WILL exit with exit code 123
*/

static int	ft_read_array_input(char *str)
{
	int	check;
	int	i;

	check = -1;
	i = 0;
	if (!str)
		return (0);
	while (!ft_isdigit(str[i]) && str[i] != '\0'
		&& str[i] != '-' && str[i] != '+')
		i++;
	if (ft_isdigit(str[i]) || str[i] == '-' || str[i] == '+')
	{
		if ((str[i] == '-' && !ft_isdigit(str[i + 1])) || (str[i] == '+'
				&& !ft_isdigit(str[i + 1])))
			return (-1);
		check = ft_atoi(str + i);
		while (ft_isdigit(str[i]) && str[i] != '\0')
			i++;
		if (str[i] != '\0')
			return (-1);
	}
	return (check);
}

void	ft_exit_minishell(char **arr, int len)
{
	int	check;

	if (!g_shell.is_pipe)
		ft_printf("exit\n");
	check = ft_read_array_input(arr[1]);
	if (check >= 0)
	{
		if (len < 3)
			exit(check);
		else
			ft_printf_err("minishell: exit: too many arguments\n");
	}
	else
	{
		ft_printf_err(
			"minishell: exit: %s: numeric argument required\n", arr[1]);
		exit(255);
	}
	g_shell.exit_code = 1;
	return ;
}
