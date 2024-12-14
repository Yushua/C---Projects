/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_err_numflags.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/28 17:34:50 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/28 23:42:41 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static long	ft_numlen(long n)
{
	long	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ft_padlen(long n, long *padlen, t_flag *flags)
{
	if (flags->dot && flags->pre < 0)
	{
		flags->pre = -1;
		flags->dot = 0;
	}
	if (flags->dot && flags->pre == 0 && n == 0)
		*padlen = flags->pad;
	else if (flags->dot && n < 0)
	{
		if (flags->pre < ft_numlen(-n))
			*padlen = flags->pad - ft_numlen(n);
		else
			*padlen = flags->pad - ft_numlen(n) - (flags->pre - ft_numlen(-n));
	}
	else if (flags->dot && n >= 0)
	{
		if (flags->pre < ft_numlen(n))
			*padlen = flags->pad - ft_numlen(n);
		else
			*padlen = flags->pad - ft_numlen(n) - (flags->pre - ft_numlen(n));
	}
	else
		*padlen = flags->pad - ft_numlen(n);
}

static	void	ft_print_negative(long *n, int *count)
{
	if (*n < 0)
	{
		pft_eputchar_fd('-', 2, count);
		*n = *n * -1;
		if (*count >= 0)
			*count = *count + 1;
	}
}

void	ft_esigned(long n, int *count, t_flag *flags)
{
	long	padlen;

	padlen = 0;
	ft_padlen(n, &padlen, flags);
	if ((!flags->dash && !flags->zero)
		|| (!flags->dash && flags->zero && flags->dot))
		ft_epad(padlen, count);
	ft_print_negative(&n, count);
	if (flags->zero && !flags->dash && flags->pre == -1)
		ft_epadzero(padlen, count);
	if (flags->dot)
		ft_epadzero(flags->pre - ft_numlen(n), count);
	if (flags->pre != 0 || (flags->pre == 0 && n != 0))
		ft_eprint_decimal(n, count);
	if (*count < 0)
		return ;
	if (flags->dash)
		ft_epad(padlen, count);
}

void	ft_eunsigned(unsigned long n, int *count, t_flag *flags)
{
	long	padlen;

	padlen = 0;
	if (*count < 0)
		return ;
	ft_padlen(n, &padlen, flags);
	if ((!flags->dash && !flags->zero)
		|| (!flags->dash && flags->zero && flags->dot))
		ft_epad(padlen, count);
	if (flags->zero && !flags->dash && flags->pre == -1)
		ft_epadzero(padlen, count);
	if (flags->dot)
		ft_epadzero(flags->pre - ft_numlen(n), count);
	if (flags->pre != 0 || (flags->pre == 0 && n != 0))
		ft_eprint_decimal((unsigned long)n, count);
	if (*count < 0)
		return ;
	if (flags->dash)
		ft_epad(padlen, count);
}
