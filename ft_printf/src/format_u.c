/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:07:26 by tomsato           #+#    #+#             */
/*   Updated: 2024/11/09 14:32:25 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_ulong_len(unsigned long n)
{
	int	count;

	count = 1;
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	get_uint_len(unsigned int n)
{
	return (get_ulong_len((unsigned long)n));
}

void	ft_putul(unsigned long int u)
{
	if (9 < u)
	{
		ft_putul(u / 10);
		ft_putul(u % 10);
	}
	else
	{
		ft_putchar_fd(u + '0', STD_OUT);
	}
}

int	format_u(va_list args)
{
	const unsigned int	u = va_arg(args, unsigned int);
	const int			count = get_uint_len(u);

	ft_putul((unsigned long int)u);
	return (count);
}
