/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:33:12 by jchin             #+#    #+#             */
/*   Updated: 2022/07/03 19:47:07 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//기존 libft에서 만들었던 함수를 인용했는데 validation 추가
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

void	*ft_memcpy(void *dst, const void *src, size_t n) //dst의 내용을 src의 내용으로 복사
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

//s1을 free해주는 작업 추가
char	*ft_strjoin(char *left_str, char *buff) //서로 문자열을 이어붙여주는 함수
{
	char	*result;
	size_t	left_str_len;
	size_t	buff_len;

	if (!left_str)//add
	{
		left_str = (char *)malloc(sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	left_str_len = ft_strlen(left_str);
	buff_len = ft_strlen(buff);
	result = (char *)malloc(sizeof(char) * (left_str_len + buff_len + 1));
	if (!result)
		return (NULL);
	ft_memcpy(result, left_str, left_str_len);
	ft_memcpy(result + left_str_len, buff, buff_len);
	result[left_str_len + buff_len] = '\0';
	free(left_str);//add
	return (result);
}
