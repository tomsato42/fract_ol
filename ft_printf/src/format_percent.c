/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:07:26 by tomsato           #+#    #+#             */
/*   Updated: 2024/11/09 14:33:25 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_percent(va_list args)
{
	const int	count = 1;

	(void)args;
	ft_putchar_fd('%', STD_OUT);
	return (count);
}
