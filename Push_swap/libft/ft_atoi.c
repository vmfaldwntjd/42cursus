/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchin <jchin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:13:09 by jchin             #+#    #+#             */
/*   Updated: 2022/03/31 20:28:24 by jchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	check_long_long_overflow(const char *str, int i, int current)
{
	if (current * 10 + (str[i] - '0') < current && \
	(long long)current * 10 + (str[i] - '0') < (long long)current)
		return (1);
	else if (current * 10 + (str[i] - '0') > current && \
	(long long)current * 10 + (str[i] - '0') < (long long)current)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	sign = 1;
	i = 0;
	result = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sign == -1 && check_long_long_overflow(str, i, result))
			return (0);
		else if (sign == 1 && check_long_long_overflow(str, i, result))
			return (-1);
		result = result * 10 + (str[i++] - '0');
	}
	return (result * sign);
}
