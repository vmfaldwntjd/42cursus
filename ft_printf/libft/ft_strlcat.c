/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:08:23 by jchin             #+#    #+#             */
/*   Updated: 2022/03/30 15:44:31 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	src_idx;
	size_t	dst_idx;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	src_idx = 0;
	dst_idx = dst_len;
	if (dstsize > dst_len)
	{
		while (dst_idx < dstsize - 1 && src[src_idx])
		{
			dst[dst_idx] = src[src_idx];
			++dst_idx;
			++src_idx;
		}
		dst[dst_idx] = '\0';
		return (dst_len + src_len);
	}
	else
		return (src_len + dstsize);
}
