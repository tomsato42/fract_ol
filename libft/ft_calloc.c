/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:24:32 by tomsato           #+#    #+#             */
/*   Updated: 2024/10/24 18:12:20 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	bytes;

	if ((nmemb == 0) || (size == 0))
		return (malloc(0));
	if ((nmemb > (size_t)INT_MAX) || (size > (size_t)INT_MAX))
		return (NULL);
	if (nmemb > (size_t)(INT_MAX / size))
		return (NULL);
	bytes = nmemb * size;
	if (bytes / nmemb != size)
		return (NULL);
	mem = malloc(bytes);
	if (!mem)
		return (NULL);
	ft_memset(mem, 0, bytes);
	return (mem);
}
