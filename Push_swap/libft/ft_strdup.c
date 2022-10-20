/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:14:45 by jchin             #+#    #+#             */
/*   Updated: 2022/03/30 20:47:54 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		size;

	size = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * size + 1);
	if (!dest)
		return (0);
	dest = ft_strcpy(dest, s1);
	return (dest);
}
