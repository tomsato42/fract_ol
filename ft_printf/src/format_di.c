/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:07:26 by tomsato           #+#    #+#             */
/*   Updated: 2024/11/09 14:32:19 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_int_len(long n)
{
	size_t	count;

	count = 1;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return ((int)count);
}

int	format_d(va_list args)
{
	const int	i = va_arg(args, int);
	const int	count = get_int_len(i);

	ft_putnbr_fd((long)i, STD_OUT);
	return (count);
}

int	format_i(va_list args)
{
	return (format_d(args));
}
