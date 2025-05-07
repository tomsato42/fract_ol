/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:27:57 by tomsato           #+#    #+#             */
/*   Updated: 2024/10/24 19:32:22 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

static int	overflowl(int sign, long i, char next)
{
	if (sign == 1)
		if (LONG_MAX / 10 < i
			|| (LONG_MAX / 10 == i && LONG_MAX % 10 <= next - '0'))
			return (1);
	if (sign == -1)
		if (LONG_MIN / -10 < i
			|| (LONG_MIN / -10 == i && LONG_MIN % -10 * -1 <= next - '0'))
			return (-1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	i;

	while (ft_isspace(*nptr))
		nptr++;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			sign = -1;
	i = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (overflowl(sign, i, *nptr) == 1)
			return ((int)LONG_MAX);
		if (overflowl(sign, i, *nptr) == -1)
			return ((int)LONG_MIN);
		i = i * 10 + *nptr - '0';
		nptr++;
	}
	return ((int)(sign * i));
}
/*
//test code
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	//ft_atoi
	printf("ft_atoi\n");
	printf("int max:%13d\n",ft_atoi("2147483647"));
	printf("int min:%13d\n",ft_atoi("-2147483648"));
	printf("int max + 1:%13d\n",ft_atoi("2147483648"));
	printf("int min - 1:%13d\n",ft_atoi("-2147483649"));
	printf("+:%13d\n",ft_atoi("+2147483649"));
	printf("--:%13d\n",ft_atoi("--2147483649"));
	printf("abc:%13d\n",ft_atoi("abc"));

	//atoi
	printf("atoi\n");
	printf("int max:%13d\n",atoi("2147483647"));
	printf("int min:%13d\n",atoi("-2147483648"));
	printf("int max + 1:%13d\n",atoi("2147483648"));
	printf("int min - 1:%13d\n",atoi("-2147483649"));
	printf("+:%13d\n",atoi("+2147483649"));
	printf("--:%13d\n",atoi("--2147483649"));
	printf("abc:%13d\n",atoi("abc"));

	return (0);
}*/
