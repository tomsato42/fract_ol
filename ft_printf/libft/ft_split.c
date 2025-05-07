/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:48:27 by tomsato           #+#    #+#             */
/*   Updated: 2024/10/29 10:32:44 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	*free_mem(char **split, size_t word_i)
{
	size_t	i;

	i = 0;
	while (i < word_i)
	{
		free(split[i]);
		i++;
	}
	return (free(split), NULL);
}

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	int		flag;

	count = 0;
	flag = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (*s == c)
		{
			flag = 0;
		}
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char			**split;
	const size_t	words_count = count_words(s, c);
	size_t			i;
	size_t			word_i;
	size_t			word_start;

	split = malloc((words_count + 1) * sizeof(char *));
	if (!s || !(split))
		return (NULL);
	word_i = 0;
	i = 0;
	while (word_i < words_count)
	{
		while (s[i] == c)
			i++;
		word_start = i;
		while ((s[i] != c) && s[i])
			i++;
		split[word_i] = ft_substr(s, word_start, i - word_start);
		if (!split[word_i])
			return (free_mem(split, word_i));
		word_i++;
	}
	split[word_i] = NULL;
	return (split);
}
