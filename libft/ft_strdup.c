/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:16:55 by tomsato           #+#    #+#             */
/*   Updated: 2024/10/26 19:21:52 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	str_length;
	char	*dest;

	str_length = ft_strlen(s);
	dest = (char *)malloc((str_length + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s, str_length + 1);
	return (dest);
}
