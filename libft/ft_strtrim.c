/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:14:48 by jchin             #+#    #+#             */
/*   Updated: 2022/03/31 14:39:47 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*result;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = (char *)s1;
	end = (char *)s1;
	while (*start && ft_strchr(set, *start))
		++start;
	if (!(*start))
		return (ft_strdup(""));
	while (*end)
		++end;
	--end;
	while ((start <= end) && ft_strchr(set, *end))
		--end;
	result = (char *)malloc((end - start + 1) + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, start, (end - start + 1) + 1);
	return (result);
}
