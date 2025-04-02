/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:32:56 by tomsato           #+#    #+#             */
/*   Updated: 2024/11/09 15:07:07 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

void	init_format_func(t_format_func *format_func)
{
	format_func[0] = format_c;
	format_func[1] = format_s;
	format_func[2] = format_p;
	format_func[3] = format_d;
	format_func[4] = format_i;
	format_func[5] = format_u;
	format_func[6] = format_smallx;
	format_func[7] = format_bigx;
	format_func[8] = format_percent;
}

int	handle_format(char format, va_list args)
{
	int					count;
	size_t				i;
	const char			*format_list = "cspdiuxX%";
	t_format_func		format_func[9];

	init_format_func(format_func);
	count = 0;
	i = 0;
	while (format_list[i])
	{
		if (format == format_list[i])
		{
			count += format_func[i](args);
			break ;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += handle_format(*format, args);
		}
		else
		{
			ft_putchar_fd(*format, STD_OUT);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
