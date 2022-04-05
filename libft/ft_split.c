/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:39:40 by jchin             #+#    #+#             */
/*   Updated: 2022/04/03 16:12:44 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static size_t	get_strs_size(char const *s, char c)
{
	size_t		size;
	int			flag;

	size = 1;
	flag = 0;
	while (*s)
	{
		if (*s != c)
			break ;
		s++;
	}
	while (*s)
	{
		if (*s == c)
		{
			if (*(s + 1) != c && *(s + 1) != 0)
				size++;
		}
		s++;
	}
	return (size);
}

static char	**frees(char **strs, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
		free(strs[i++]);
	free(strs);
	return (0);
}

char	*get_end(char c, char const *s)
{
	char	*result;

	result = (char *)s;
	while (*result && *result != c)
		result++;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	char	*end;
	size_t	index;

	index = 0;
	strs = (char **)malloc(sizeof(char *) * (get_strs_size(s, c) + 1));
	if (!strs)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			end = get_end(c, s);
			strs[index] = (char *)malloc(end - s + 1);
			if (!(strs[index]))
				return (frees(strs, index - 1));
			ft_strlcpy(strs[index++], (char *)s, end - s + 1);
			s = end;
		}
		else
			s++;
	}
	strs[index] = 0;
	return (strs);
}
