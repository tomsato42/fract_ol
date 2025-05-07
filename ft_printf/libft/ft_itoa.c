/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:56:04 by tomsato           #+#    #+#             */
/*   Updated: 2024/10/29 02:18:20 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*set_s(char *s, long long n, size_t s_len)
{
	size_t	flag;

	flag = 0;
	s[s_len] = '\0';
	s_len--;
	if (n < 0)
	{
		n *= -1;
		s[0] = '-';
		flag = 1;
	}
	while (1)
	{
		s[s_len] = n % 10 + '0';
		n /= 10;
		if (s_len == flag)
			break ;
		s_len--;
	}
	return (s);
}

static size_t	get_s_len(long long n)
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
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	s_len;
	char	*s;

	s_len = get_s_len((long long)n);
	s = (char *)malloc((s_len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	return (set_s(s, (long long)n, s_len));
}
