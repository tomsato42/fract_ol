/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:25:12 by tomsato           #+#    #+#             */
/*   Updated: 2024/10/24 19:44:57 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	sum_len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	sum_len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((sum_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, sum_len + 1);
	ft_strlcat(str, s2, sum_len + 1);
	return (str);
}
