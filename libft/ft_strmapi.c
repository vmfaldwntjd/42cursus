/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:42:36 by jchin             #+#    #+#             */
/*   Updated: 2022/03/31 14:44:30 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	len;
	size_t	idx;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	idx = 0;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (idx < len)
	{
		result[idx] = f(idx, s[idx]);
		++idx;
	}
	result[idx] = 0;
	return (result);
}
