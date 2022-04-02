/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:14:52 by jchin             #+#    #+#             */
/*   Updated: 2022/03/31 21:26:21 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static size_t	get_strs_count(char const *s, char c)
{
	size_t	cnt_result;
	size_t	i;

	i = 0;
	cnt_result = 0;
	while (s[i] && s[i] == c)
		++i;
	while (s[i])
	{
		if (s[i] == c)
			cnt_result += 1;
		++i;
	}
	return (cnt_result);
}

static void	set_null(char **result, size_t mx_idx)
{
	size_t	index;

	index = 0;
	while (index < mx_idx)
		free(result[index++]);
	free(result);
}

static int	get_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		++i;
	return (i);
}

static char	*get_string(char **result, size_t idx, char const *s, char c)
{
	char	*s_tmp;
	int		i;
	int		len;

	len = get_len(s, c);
	i = 0;
	s_tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!s_tmp)
	{
		set_null(result, idx);
		return (0);
	}
	while (i < len)
	{
		s_tmp[i] = s[i];
		++i;
	}
	s_tmp[i] = '\0';
	return (s_tmp);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	idx;

	if (!s)
		return (0);
	idx = 0;
	result = (char **)malloc(sizeof(char *) * get_strs_count(s, c) + 1);
	if (!result)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (*s && *s != c)
		{
			result[idx] = get_string(result, idx, s, c);
			++idx;
		}
		while (*s && *s != c)
			++s;
	}
	result[idx] = 0;
	return (result);
}
