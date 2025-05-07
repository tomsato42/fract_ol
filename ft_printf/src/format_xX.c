/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_xX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:07:26 by tomsato           #+#    #+#             */
/*   Updated: 2024/11/09 14:33:16 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned int x)
{
	int	count;

	count = 1;
	while (15 < x)
	{
		count++;
		x /= 16;
	}
	return (count);
}

void	put_hex(unsigned long int hex, char *hex_table)
{
	if (15 < hex)
	{
		put_hex(hex / 16, hex_table);
		put_hex(hex % 16, hex_table);
	}
	else
	{
		ft_putchar_fd(hex_table[hex], STD_OUT);
	}
}

int	format_smallx(va_list args)
{
	const unsigned int	x = va_arg(args, unsigned int);
	const int			count = hex_len(x);

	put_hex(x, HEX_SMALL);
	return (count);
}

int	format_bigx(va_list args)
{
	const unsigned int	x = va_arg(args, unsigned int);
	const int			count = hex_len(x);

	put_hex(x, HEX_BIG);
	return (count);
}
