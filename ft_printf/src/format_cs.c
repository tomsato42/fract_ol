/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_cs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:07:26 by tomsato           #+#    #+#             */
/*   Updated: 2024/11/09 14:09:34 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_c(va_list args)
{
	int	count;

	count = 0;
	ft_putchar_fd(va_arg(args, int), STD_OUT);
	count++;
	return (count);
}

int	format_s(va_list args)
{
	int		count;
	char	*str;

	count = 0;
	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	ft_putstr_fd(str, STD_OUT);
	count += (int)ft_strlen(str);
	return (count);
}
