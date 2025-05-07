/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:07:26 by tomsato           #+#    #+#             */
/*   Updated: 2024/11/09 14:09:55 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_memlen(void *ptr)
{
	size_t			len;
	unsigned long	tmp;

	len = 0;
	tmp = (unsigned long)ptr;
	if (tmp == 0)
		return (1);
	while (tmp > 0)
	{
		tmp /= 16;
		len++;
	}
	return (len);
}

size_t	put_memaddr(void *ptr, char *hex)
{
	const size_t	addr_len = get_memlen(ptr);
	char			buffer[17];
	size_t			i;
	unsigned long	tmp;

	i = addr_len;
	buffer[i] = '\0';
	tmp = (unsigned long)ptr;
	if (tmp == 0)
		buffer[--i] = '0';
	while (i--)
	{
		buffer[i] = hex[tmp % 16];
		tmp /= 16;
	}
	if (ptr != NULL)
		ft_putstr_fd("0x", 1);
	else
		return (ft_strlcpy(buffer, "(nil)", 17), ft_putstr_fd(buffer, STD_OUT),
			5);
	return (ft_putstr_fd(buffer, STD_OUT), addr_len + 2);
}

int	format_p(va_list args)
{
	int	count;

	count = put_memaddr(va_arg(args, void *), HEX_SMALL);
	return (count);
}
