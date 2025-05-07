/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:17:21 by tomsato           #+#    #+#             */
/*   Updated: 2025/04/03 10:20:56 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fractol.h"

static int	process_sign(const char *str, int *i)
{
	double	sign;

	sign = 1.0;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1.0;
		(*i)++;
	}
	return (sign);
}

static double	process_decimal(const char *str, int *i)
{
	double	result;
	double	decimal;

	result = 0.0;
	if (str[*i] == '.')
	{
		(*i)++;
		decimal = 0.1;
		while (ft_isdigit(str[*i]))
		{
			result += (str[*i] - '0') * decimal;
			decimal *= 0.1;
			(*i)++;
		}
	}
	return (result);
}

double	ft_atof(const char *str)
{
	double	result;
	double	sign;
	int		i;

	result = 0.0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = process_sign(str, &i);
	while (ft_isdigit(str[i]))
		result = result * 10.0 + (str[i++] - '0');
	result += process_decimal(str, &i);
	return (result * sign);
}
