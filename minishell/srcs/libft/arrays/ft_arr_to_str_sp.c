/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arr_to_str_sp.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 18:54:07 by nhariman      #+#    #+#                 */
/*   Updated: 2021/03/18 18:46:52 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_arr_to_str_sp(char **arr)
{
	int		i;
	char	*new_str;
	char	*tmp;
	char	*output;

	new_str = ft_charjoin(arr[0], ' ');
	i = 1;
	while (arr[i] != (char *) 0)
	{
		output = ft_charjoin(arr[i], ' ');
		tmp = gnl_strjoin(new_str, output);
		free(output);
		new_str = tmp;
		i++;
	}
	return (new_str);
}
