/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:17:32 by tomsato           #+#    #+#             */
/*   Updated: 2024/11/02 14:03:45 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while ((i < len) && (big[i] != '\0'))
	{
		j = 0;
		while ((big[i + j] != '\0') && (little[j] != '\0') && ((i + j) < len)
			&& (big[i + j] == little[j]))
			j++;
		if (little[j] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}

	/*20 if (!big || !little)*/
	/*21 return (NULL);*/
