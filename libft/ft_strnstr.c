/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:12:34 by jchin             #+#    #+#             */
/*   Updated: 2022/03/31 14:02:58 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	tmp;

	if (!(*needle))
		return((char *)haystack);
	i = 0;
	while (i < len)
	{
		tmp = 0;
		if (needle[tmp] == haystack[i + tmp])
		{
			while (needle[tmp] && haystack[i + tmp])
			{
				if (needle[tmp] != haystack[i + tmp] || (i + tmp) >= len)
					break ;
				++tmp;
			}
			if (needle[tmp] == '\0')
				return (&((char *)haystack)[i]);
		}
		++i;
	}
	return (0);
}
