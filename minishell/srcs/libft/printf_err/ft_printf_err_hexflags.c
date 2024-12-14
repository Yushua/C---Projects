/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_err_hexflags.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 18:38:45 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/28 23:41:45 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static long	ft_hexlen(unsigned long n)
{
	long		len;

	len = 1;
	while (n >= 16)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static void	ft_hexpadlen(unsigned long n, long *padlen, t_flag *flags)
{
	if (flags->dot > 0 && flags->pre < 0)
	{
		flags->pre = -1;
		flags->dot = 0;
	}
	if (flags->dot > 0 && flags->pre <= 0 && n == 0)
		*padlen = flags->pad;
	else if (flags->dot > 0 && n != 0)
	{
		if (flags->pre < ft_hexlen(-n))
			*padlen = flags->pad - ft_hexlen(n);
		else
			*padlen = flags->pad - ft_hexlen(n) - (flags->pre - ft_hexlen(-n));
	}
	else if (flags->dot > 0)
	{
		if (flags->pre < ft_hexlen(n))
			*padlen = flags->pad - ft_hexlen(n);
		else
			*padlen = flags->pad - ft_hexlen(n) - (flags->pre - ft_hexlen(n));
	}
	else
		*padlen = flags->pad - ft_hexlen(n);
}

void	ft_ehex(char c, unsigned long n, int *count, t_flag *flags)
{
	long	padlen;

	padlen = 0;
	ft_hexpadlen(n, &padlen, flags);
	if ((!flags->dash && !flags->zero)
		|| (!flags->dash && flags->zero && flags->dot))
		ft_epad(padlen, count);
	if (flags->zero > 0 && !flags->dash && flags->pre == -1)
		ft_epadzero(padlen, count);
	if (flags->dot)
		ft_epadzero(flags->pre - ft_hexlen(n), count);
	if (flags->pre != 0 || (flags->pre == 0 && n != 0))
		ft_eprint_hex(c, (unsigned long)n, count);
	if (*count < 0)
		return ;
	if (flags->dash > 0)
		ft_epad(padlen, count);
}

void	ft_eptr(unsigned long n, int *count, t_flag *flags)
{
	long	padlen;

	padlen = 0;
	ft_hexpadlen(n, &padlen, flags);
	if ((!flags->dash && !flags->zero)
		|| (!flags->dash && flags->zero && flags->dot))
		ft_epad(padlen - 2, count);
	if (flags->zero && !flags->dash && flags->pre == -1)
		ft_epadzero(padlen, count);
	pft_eputstr_fd("0x", 2, count);
	if (*count < 0)
		return ;
	*count = *count + ft_strlen("0x");
	if (flags->dot)
		ft_epadzero(flags->pre - ft_hexlen(n), count);
	if (flags->pre != 0 || (flags->pre == 0 && n != 0))
		ft_eprint_hex('p', (unsigned long)n, count);
	if (*count < 0)
		return ;
	if (flags->dash > 0)
		ft_epad(padlen - 2, count);
}
