/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:33:12 by jchin             #+#    #+#             */
/*   Updated: 2022/07/04 01:01:07 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str) //add
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		++i;
	}
	return (dst);
}


char	*ft_strchr(char *s, int c)
{
	if (!s) //add
		return (0);
	while (*s && *s != (char)c)
		++s;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *current_str, char *buff)
{
	char	*result;
	size_t	current_str_len;
	size_t	buff_len;

	if (!current_str)
	{
		current_str = (char *)malloc(sizeof(char));
		current_str[0] = '\0';
	}
	if (!current_str || !buff)
		return (NULL);
	current_str_len = ft_strlen(current_str);
	buff_len = ft_strlen(buff);
	result = (char *)malloc(sizeof(char) * (current_str_len + buff_len + 1));
	if (!result)
		return (NULL);
	ft_memcpy(result, current_str, current_str_len);
	ft_memcpy(result + current_str_len, buff, buff_len);
	result[current_str_len + buff_len] = '\0';
	free(current_str);
	return (result);
}
