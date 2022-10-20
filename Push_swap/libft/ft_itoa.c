/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:57:54 by jchin             #+#    #+#             */
/*   Updated: 2022/03/31 21:14:29 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	get_len(int n)
{
	int	result;

	result = 0;
	if (n <= 0)
		++result;
	while (n)
	{
		++result;
		n /= 10;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		str_len;
	long	nb;

	str_len = get_len(n);
	result = (char *)malloc(sizeof(char) * str_len + 1);
	if (!result)
		return (NULL);
	nb = n;
	result[str_len--] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		result[0] = '-';
	}
	if (nb == 0)
		result[0] = '0';
	while (nb)
	{
		result[str_len--] = '0' + (nb % 10);
		nb /= 10;
	}
	return (result);
}
