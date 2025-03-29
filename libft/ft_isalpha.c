/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:50:43 by tomsato           #+#    #+#             */
/*   Updated: 2024/10/22 20:10:50 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int					test[] = {'a', 'z', 'A', 'Z', '0', -1};
	static const size_t	size = sizeof(test) / sizeof(*test);

	//ft_isalpha
	printf("↓ここから自分の↓\n");
	for (size_t i = 0; i < size; i++)
		printf("%d\n",ft_isalpha(test[i]));
	//isalpha
	printf("↓ここから他人の↓\n");
	printf("%d\n",isalpha('a'));
	printf("%d\n",isalpha('z'));
	printf("%d\n",isalpha('A'));
	printf("%d\n",isalpha('Z'));
	printf("%d\n",isalpha('0'));
	printf("%d\n",isalpha(-1));
	return(0);
}
*/
